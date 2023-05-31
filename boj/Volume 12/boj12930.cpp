#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> A(N);
	vector<string> B(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	for (int i = 0; i < N; ++i) {
		getline(cin, B[i]);
	}
	vector<vector<int>> D(N, vector<int>(9 * N - 8, INF));
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	pq.push({D[0][0] = 0, 0, 0});
	while (pq.size()) {
		auto [d, u, x] = pq.top(); pq.pop();
		for (int v = 0; v < N; ++v) {
			if (A[u][v] == '.') {
				continue;
			}
			int y = x + A[u][v] - '0';
			int nd = d + B[u][v] - '0';
			if (y < D[u].size() && D[v][y] > nd) {
				pq.push({D[v][y] = nd, v, y});
			}
		}
	}
	int ans = INF;
	for (int i = 0; i < D[1].size(); ++i) {
		if (D[1][i] < INF) {
			ans = min(ans, i * D[1][i]);
		}
	}
	cout << (ans == INF ? -1 : ans) << "\n";
	return 0;
}
