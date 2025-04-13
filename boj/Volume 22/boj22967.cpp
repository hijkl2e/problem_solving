#include <bits/stdc++.h>

using namespace std;

using edge = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<deque<bool>> A(N + 1, deque<bool>(N + 1));
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{};
		cin >> u >> v;
		A[u][v] = A[v][u] = true;
	}
	vector<edge> E;
	if (N < 5) {
		for (int i = 1; i <= N; ++i) {
			for (int j = i + 1; j <= N; ++j) {
				if (!A[i][j]) {
					E.push_back({i, j});
				}
			}
		}
	} else {
		for (int i = 2; i <= N; ++i) {
			if (!A[1][i]) {
				E.push_back({1, i});
			}
		}
	}
	cout << E.size() << "\n";
	cout << (N < 5 ? 1 : 2) << "\n";
	for (auto &[x, y] : E) {
		cout << x << " " << y << "\n";
	}
	return 0;
}
