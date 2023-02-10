#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

struct rec {
	ll a{}, b{}, c{}, d{};
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> H(N + 1);
	vector<int> S(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> H[i] >> S[i];
	}
	vector<vector<ll>> dp(M + 1, vector<ll>(N + 1, -INF));
	dp[0][0] = 0;
	for (int i = 1; i <= M; ++i) {
		stack<rec> st;
		for (int j = 1; j <= N; ++j) {
			ll maxv = dp[i - 1][j - 1];
			while (st.size() && st.top().a < H[j]) {
				maxv = max(maxv, st.top().c);
				st.pop();
			}
			if (st.size() && st.top().a == H[j]) {
				auto &[a, b, c, d] = st.top();
				c = max(c, maxv);
				b = max(b, c) + S[j];
				d = max(b, d);
			} else {
				st.push({H[j], maxv + S[j], maxv, max(maxv + S[j], st.size() ? st.top().d : 0)});
			}
			dp[i][j] = st.top().d;
		}
	}
	cout << dp[M][N] << "\n";
	return 0;
}
