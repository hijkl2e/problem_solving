#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll solve(string &s, int p1, int p2, char c) {
	static vector<int> v1(4);
	static vector<int> v2(4);
	v1[0] = (p2 >> 2) - 1;
	for (int i = 1; i < 3; ++i) {
		v1[i] = v1[i - 1] + ((p2 >> (2 - i)) & 1);
	}
	for (int i = 1; i < 4; ++i) {
		v2[i] = s[p1 + i - 2] == c ? v1[i - 1] + 1 : max(v1[i], v2[i - 1]);
	}
	if (v2[2] < 1) {
		return 0;
	}
	int ret{};
	for (int i = 1; i < 4; ++i) {
		ret = 2 * ret + (v2[i] - v2[i - 1]);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	string S;
	getline(cin, S);
	for (auto &c : S) {
		c = toupper(c);
	}
	S = "#" + S + "#";
	vector<vector<ll>> dp(2, vector<ll>(8));
	dp[1][6] = 1;
	vector<int> A(91);
	for (int i = 0; i < 3; ++i) {
		++A[S[i]];
	}
	for (int i = 1; i < S.size() - 1; ++i) {
		copy(dp[1].begin(), dp[1].end(), dp[0].begin());
		fill(dp[1].begin(), dp[1].end(), 0);
		int cnt{};
		for (char c = 'A' + M - 1; c >= '@'; --c) {
			if (c >= 'A' && A[c] == 0) {
				++cnt;
				continue;
			}
			for (int j = 2; j < 8; ++j) {
				if (dp[0][j] == 0) {
					continue;
				}
				int k = solve(S, i, j, c);
				dp[1][k] += (c == '@' ? cnt : 1) * dp[0][j];
			}
		}
		++A[S[i + 2]];
		--A[S[i - 1]];
	}
	ll ans = accumulate(dp[1].begin() + 2, dp[1].end(), 0LL) - 1;
	cout << ans << "\n";
	return 0;
}
