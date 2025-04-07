#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, T{};
	cin >> N >> T;
	vector<int> x(N + 1);
	vector<int> y(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> x[i] >> y[i];
	}
	vector<vector<ii>> A(T + 3);
	for (int i = 0; i <= N; ++i) {
		A[y[i]].push_back({x[i], i});
	}
	for (int i = 0; i <= T; ++i) {
		sort(A[i].begin(), A[i].end());
	}
	vector<vector<int>> G(N + 1);
	for (int i = 0; i <= T; ++i) {
		for (auto &[x, j] : A[i]) {
			for (int k = 0; k < 3; ++k) {
				auto it = lower_bound(A[i + k].begin(), A[i + k].end(), make_pair(x - 2, -1));
				while (it != A[i + k].end() && it->first < x + 3) {
					G[j].push_back(it->second);
					G[it->second].push_back(j);
					++it;
				}
			}
		}
	}
	vector<int> D(N + 1, INF);
	queue<int> q;
	D[0] = 0;
	q.push(0);
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int v : G[u]) {
			if (D[v] == INF) {
				D[v] = D[u] + 1;
				q.push(v);
			}
		}
	}
	int ans = INF;
	for (int i = 0; i <= N; ++i) {
		if (y[i] == T) {
			ans = min(ans, D[i]);
		}
	}
	if (ans == INF) {
		ans = -1;
	}
	cout << ans << "\n";
	return 0;
}
