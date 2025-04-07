#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

const ll INF = 4e18;

vector<ll> D;
vector<vector<ll>> dp;

void solve(int L, int R, int optL, int optR) {
	if (L > R) {
		return;
	}
	int j = (L + R) / 2;
	dp[1][j] = INF;
	int opt{};
	for (int k = optL; k <= optR && k < j; ++k) {
		ll val = dp[0][k] + (D[j] - D[k]) * (j - k - 1);
		if (dp[1][j] > val) {
			dp[1][j] = val;
			opt = k;
		}
	}
	solve(L, j - 1, optL, opt);
	solve(j + 1, R, opt, optR);
}

vector<ll> dijkstra(vector<vector<ii>> &G, int s) {
	vector<ll> D(G.size(), INF);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({D[s] = 0, s});
	while (pq.size()) {
		auto [d, u] = pq.top(); pq.pop();
		if (D[u] < d) {
			continue;
		}
		for (auto &[v, w] : G[u]) {
			if (D[v] > D[u] + w) {
				pq.push({D[v] = D[u] + w, v});
			}
		}
	}
	return D;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, B{}, S{}, R{};
	cin >> N >> B >> S >> R;
	vector<vector<ii>> G(N + 1);
	vector<vector<ii>> H(N + 1);
	while (R--) {
		int u{}, v{}, l{};
		cin >> u >> v >> l;
		G[u].push_back({v, l});
		H[v].push_back({u, l});
	}
	vector<ll> d1 = dijkstra(G, B + 1);
	vector<ll> d2 = dijkstra(H, B + 1);
	D.resize(B + 1);
	for (int i = 1; i <= B; ++i) {
		D[i] = d1[i] + d2[i];
	}
	sort(D.begin(), D.end());
	partial_sum(D.begin(), D.end(), D.begin());
	dp.assign(2, vector<ll>(B + 1, INF));
	dp[0][0] = 0;
	for (int i = 1; i <= S; ++i) {
		solve(i, B - S + i, i - 1, B - S + i - 1);
		copy(dp[1].begin(), dp[1].end(), dp[0].begin());
	}
	cout << dp[0][B] << "\n";
	return 0;
}
