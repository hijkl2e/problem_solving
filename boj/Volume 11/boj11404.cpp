#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> D(N + 1, vector<int>(N + 1, INF));
	for (int i = 1; i <= N; ++i) {
		D[i][i] = 0;
	}
	while (M--) {
		int a{}, b{}, c{};
		cin >> a >> b >> c;
		D[a][b] = min(D[a][b], c);
	}
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cout << (D[i][j] == INF ? 0 : D[i][j]) << (j == N ? "\n" : " ");
		}
	}
	return 0;
}
