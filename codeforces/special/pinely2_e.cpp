#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{}, K{};
		cin >> N >> M >> K;
		vector<ll> A(N + 1);
		for (int i = 1; i <= N; ++i) {
			cin >> A[i];
		}
		vector<vector<int>> G(N + 1);
		vector<vector<int>> H(N + 1);
		while (M--) {
			int a{}, b{};
			cin >> a >> b;
			G[a].push_back(b);
			H[b].push_back(a);
		}
		vector<ll> dp(A.begin(), A.end());
		for (int u = 1; u <= N; ++u) {
			dp[u] = (dp[u] / K + (dp[u] % K > A[u])) * K + A[u];
			for (int v : G[u]) {
				dp[v] = max(dp[v], dp[u]);
			}
		}
		vector<ll> B(dp.begin(), dp.end());
		for (int u = N; u > 0; --u) {
			for (int v : H[u]) {
				if (dp[v] + K > dp[u]) {
					B[v] = max(B[v], B[u]);
				}
			}
		}
		vector<ii> C;
		for (int i = 1; i <= N; ++i) {
			if (H[i].empty()) {
				C.push_back({dp[i], B[i]});
			}
		}
		sort(C.begin(), C.end());
		ll maxv = *max_element(dp.begin(), dp.end());
		ll ans = maxv - C[0].first;
		for (int i = 0; i < C.size() - 1; ++i) {
			maxv = max(maxv, C[i].second + K);
			ans = min(ans, maxv - C[i + 1].first);
		}
		cout << ans << "\n";
	}
	return 0;
}
