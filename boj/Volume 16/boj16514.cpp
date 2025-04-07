#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{}, N{}, M{};
	cin >> K >> N >> M;
	int A[10][13][13]{};
	while (M--) {
		int u{}, v{}, d{}, z{};
		cin >> u >> v >> d >> z;
		A[d][u][v] = z;
	}
	int B[10][13]{};
	for (int i = 0; i < K * N; ++i) {
		int a{}, b{}, c{};
		cin >> a >> b >> c;
		B[b][a] = c;
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= K; ++j) {
			for (int k = 1; k <= K; ++k) {
				B[i][j] -= A[i][j][k];
				B[i + 1][k] += A[i][j][k];
			}
		}
		for (int j = 1; j <= K; ++j) {
			B[i + 1][j] += B[i][j];
		}
	}
	bool yes = true;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= K; ++j) {
			yes &= B[i][j] >= 0;
		}
	}
	cout << (yes ? "optimal" : "suboptimal") << "\n";
	return 0;
}
