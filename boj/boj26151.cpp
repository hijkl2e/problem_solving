#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> nato{
		"ALFA", "BRAVO", "CHARLIE", "DELTA", "ECHO", "FOXTROT", "GOLF",
		"HOTEL", "INDIA", "JULIETT", "KILO", "LIMA", "MIKE", "NOVEMBER",
		"OSCAR", "PAPA", "QUEBEC", "ROMEO", "SIERRA", "TANGO", "UNIFORM",
		"VICTOR", "WHISKEY", "XRAY", "YANKEE", "ZULU"
	};
	vector<vector<ll>> dp(31, vector<ll>(26));
	for (int i = 0; i < 26; ++i) {
		dp[0][i] = 1;
	}
	for (int i = 1; i < 31; ++i) {
		for (int j = 0; j < 26; ++j) {
			for (char c : nato[j]) {
				dp[i][j] += dp[i - 1][c - 'A'];
			}
			dp[i][j] = min(dp[i][j], INF);
		}
	}
	string S;
	int Q{};
	cin >> S >> Q;
	int X{};
	vector<ll> psum(S.size());
	for (int i = 0; i < psum.size(); ++i) {
		psum[i] = i + 1;
	}
	while (Q--) {
		ll q{}, x{};
		cin >> q >> x;
		if (q == 1) {
			if (X < 30) {
				X = min(X + x, 30LL);
				psum[0] = dp[X][S[0] - 'A'];
				for (int i = 1; i < S.size(); ++i) {
					psum[i] = min(psum[i - 1] + dp[X][S[i] - 'A'], INF);
				}
			}
			continue;
		}
		int idx = lower_bound(psum.begin(), psum.end(), x) - psum.begin();
		if (idx) {
			x -= psum[idx - 1];
		}
		char d = S[idx];
		for (int i = X - 1; i >= 0; --i) {
			for (char c : nato[d - 'A']) {
				if (x <= dp[i][c - 'A']) {
					d = c;
					break;
				}
				x -= dp[i][c - 'A'];
			}
		}
		cout << d;
	}
	cout << "\n";
	return 0;
}
