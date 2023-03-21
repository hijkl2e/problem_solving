#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int mod(string &s, int K) {
	int ret{};
	for (char c : s) {
		ret = (10 * ret + c - '0') % K;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	int K{};
	cin >> K;
	vector<vector<int>> B(N, vector<int>(701));
	for (int i = 0; i < N; ++i) {
		B[i][0] = mod(A[i], K);
		for (int j = 1; j < B[i].size(); ++j) {
			B[i][j] = 10 * B[i][j - 1] % K;
		}
	}
	vector<vector<ll>> dp(1 << N, vector<ll>(K));
	dp[0][0] = 1;
	for (int i = 0; i < dp.size(); ++i) {
		int len{};
		for (int j = 0; j < N; ++j) {
			if (i & (1 << j)) {
				len += A[j].size();
			}
		}
		for (int j = 0; j < N; ++j) {
			if (i & (1 << j)) {
				continue;
			}
			for (int k = 0; k < K; ++k) {
				dp[i | (1 << j)][(k + B[j][len]) % K] += dp[i][k];
			}
		}
	}
	ll n = dp.back()[0];
	ll d = 1;
	for (int i = 1; i <= N; ++i) {
		d *= i;
	}
	ll g = gcd(n, d);
	n /= g, d /= g;
	cout << n << "/" << (n ? d : 1) << "\n";
	return 0;
}
