#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, C{}, M{};
	cin >> N >> C >> M;
	vector<vector<ii>> G(N + 1);
	while (M--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
	}
	vector<int> A(N + 1);
	int ans{};
	for (int i = 1; i <= N; ++i) {
		ans += A[i];
		A[i] = 0;
		for (auto &[v, w] : G[i]) {
			A[v] += w;
		}
		int cnt = C;
		for (int j = i + 1; j <= N; ++j) {
			A[j] = min(A[j], cnt);
			cnt -= A[j];
		}
	}
	cout << ans << "\n";
	return 0;
}
