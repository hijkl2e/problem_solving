#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> D(N + 1, vector<int>(N + 1, INF));
	while (M--) {
		int a{}, b{}, t{};
		cin >> a >> b >> t;
		D[a][b] = t;
	}
	for (int i = 1; i <= N; ++i) {
		D[i][i] = 0;
	}
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				D[i][j] = min(D[i][k] + D[k][j], D[i][j]);
			}
		}
	}
	int K{};
	cin >> K;
	vector<int> A(K);
	for (int i = 0; i < K; ++i) {
		cin >> A[i];
	}
	vector<int> B(N + 1);
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < K; ++j) {
			B[i] = max(B[i], D[A[j]][i] + D[i][A[j]]);
		}
	}
	int minv = *min_element(B.begin() + 1, B.end());
	vector<int> C;
	for (int i = 1; i <= N; ++i) {
		if (B[i] == minv) {
			C.push_back(i);
		}
	}
	for (int i = 0; i < C.size(); ++i) {
		cout << C[i] << (i == C.size() - 1 ? "\n" : " ");
	}
	return 0;
}
