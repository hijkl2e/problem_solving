#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	vector<iii> B;
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			B.push_back({A[i][j], i, j});
		}
	}
	sort(B.begin(), B.end());
	vector<vector<int>> D(N, vector<int>(N, INF));
	for (int i = 0; i < N; ++i) {
		D[i][i] = 0;
	}
	int ans{};
	for (auto &[w, u, v] : B) {
		if (D[u][v] == w) {
			continue;
		}
		D[u][v] = D[v][u] = w;
		for (int k = 0; k < N; ++k) {
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
				}
			}
		}
		ans += w;
	}
	cout << (A == D ? ans : -1) << "\n";
	return 0;
}
