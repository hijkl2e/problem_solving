#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> D(N + 1, vector<int>(N + 1, INF));
	for (int i = 1; i <= N; ++i) {
		D[i][i] = 0;
	}
	int u{}, v{};
	while (cin >> u >> v, u != -1) {
		D[u][v] = D[v][u] = 1;
	}
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
	int minv = 1e9;
	vector<int> A;
	for (int i = 1; i <= N; ++i) {
		int val = *max_element(D[i].begin() + 1, D[i].end());
		if (minv > val) {
			minv = val;
			A.clear();
		}
		if (minv == val) {
			A.push_back(i);
		}
	}
	cout << minv << " " << A.size() << "\n";
	for (int i = 0; i < A.size(); ++i) {
		cout << A[i] << (i == A.size() - 1 ? "\n" : " ");
	}
	return 0;
}
