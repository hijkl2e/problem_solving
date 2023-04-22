#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

ll solve(string &s, int p1, int p2, char c) {
	static vector<int> v1(8);
	static vector<int> v2(8);
	v1[0] = (p2 >> 6) - 1;
	for (int i = 1; i < 7; ++i) {
		v1[i] = v1[i - 1] + ((p2 >> (6 - i)) & 1);
	}
	for (int i = 1; i < 8; ++i) {
		v2[i] = s[p1 + i - 4] == c ? v1[i - 1] + 1 : max(v1[i], v2[i - 1]);
	}
	if (v2[4] < 3) {
		return 0;
	}
	int ret{};
	for (int i = 1; i < 8; ++i) {
		ret = 2 * ret + (v2[i] - v2[i - 1]);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int K{};
	cin >> K;
	S = "###" + S + "###";
	vector<vector<ll>> dp(2, vector<ll>(256));
	dp[1][64 * K + 56] = 1;
	vector<int> A(91);
	for (int i = 3 - K; i < K + 4; ++i) {
		++A[S[i]];
	}
	for (int i = 3; i < S.size() - 3; ++i) {
		copy(dp[1].begin(), dp[1].end(), dp[0].begin());
		fill(dp[1].begin(), dp[1].end(), 0);
		int cnt{};
		for (char c = 'Z'; c >= '@'; --c) {
			if (c >= 'A' && A[c] == 0) {
				++cnt;
				continue;
			}
			for (int j = 56; j < 256; ++j) {
				if (dp[0][j] == 0) {
					continue;
				}
				int k = solve(S, i, j, c);
				dp[1][k] = (dp[1][k] + (c == '@' ? cnt : 1) * dp[0][j]) % MOD;
			}
		}
		++A[S[i + K + 1]];
		--A[S[i - K]];
	}
	ll ans = accumulate(dp[1].begin() + 56, dp[1].end(), 0LL) % MOD;
	cout << ans << "\n";
	return 0;
}
