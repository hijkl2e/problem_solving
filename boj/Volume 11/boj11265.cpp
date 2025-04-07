#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> D(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> D[i][j];
		}
	}
	for (int k = 0; k < N; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
	while (M--) {
		int a{}, b{}, c{};
		cin >> a >> b >> c;
		--a, --b;
		cout << (D[a][b] <= c ? "Enjoy other party" : "Stay here") << "\n";
	}
	return 0;
}
