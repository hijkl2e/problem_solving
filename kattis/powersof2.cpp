#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<int> get_pi(string &s) {
	vector<int> pi(s.size());
	for (int i = 1; i < pi.size(); ++i) {
		int j = pi[i - 1];
		while (j && s[i] != s[j]) {
			j = pi[j - 1];
		}
		if (s[i] == s[j]) {
			pi[i] = ++j;
		}
	}
	return pi;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, E{};
	cin >> N >> E;
	string sn = to_string(N);
	string p2 = to_string(1LL << E);
	vector<int> A(sn.size());
	vector<int> B(p2.size());
	for (int i = 0; i < A.size(); ++i) {
		A[i] = sn[i] - '0';
	}
	for (int i = 0; i < B.size(); ++i) {
		B[i] = p2[i] - '0';
	}
	vector<int> pi = get_pi(p2);
	ll dp[20][10][2][20]{};
	ll go[20][10]{};
	for (int i = 0; i <= A[0]; ++i) {
		dp[0][i][i < A[0]][B[0] == i] = 1;
	}
	for (int i = 0; i < B.size(); ++i) {
		for (int j = 0; j < 10; ++j) {
			int k = i;
			while (k && B[k] != j) {
				k = pi[k - 1];
			}
			if (B[k] == j) {
				++k;
			}
			go[i][j] = k;
		}
	}
	for (int i = 0; i < 10; ++i) {
		go[B.size()][i] = B.size();
	}
	for (int i = 0; i < sn.size() - 1; ++i) {
		for (int j = 0; j < 10; ++j) {
			for (int k = 0; k < 2; ++k) {
				for (int l = 0; l <= p2.size(); ++l) {
					for (int m = k ? 9 : A[i + 1]; m >= 0; --m) {
						dp[i + 1][m][k | (m < A[i + 1])][go[l][m]] += dp[i][j][k][l];
					}
				}
			}
		}
	}
	ll ans{};
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 2; ++j) {
			ans += dp[sn.size() - 1][i][j][p2.size()];
		}
	}
	cout << ans << "\n";
	return 0;
}
