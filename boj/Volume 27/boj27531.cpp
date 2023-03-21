#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

vector<vector<ii>> G;
deque<bool> vst;
vector<int> A;

void dfs(int u, bool f) {
	if (vst[u]) {
		return;
	}
	vst[u] = true;
	for (auto &[v, w] : G[u]) {
		if (!f && vst[v]) {
			continue;
		}
		A.push_back(w);
		dfs(v, false);
	}
}

int solve() {
	int x = A[0];
	int y = A[0] + A[1];
	for (int i = 2; i < A.size(); ++i) {
		int z = min(x, y) + A[i];
		x = y, y = z;
	}
	return min(x, y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	G.resize(N + 1);
	for (int i = 0; i < N; ++i) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	for (int i = 1; i <= N; ++i) {
		auto &[v1, w1] = G[i][0];
		auto &[v2, w2] = G[i][1];
		if (v1 == v2) {
			w1 = w2 = min(w1, w2);
		}
	}
	vst.resize(N + 1);
	int ans{};
	for (int i = 1; i <= N; ++i) {
		if (vst[i]) {
			continue;
		}
		A.clear();
		dfs(i, true);
		int res = solve();
		rotate(A.begin(), A.begin() + 1, A.end());
		res = min(res, solve());
		ans += res;
	}
	cout << ans << "\n";
	return 0;
}
