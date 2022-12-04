#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		vector<vector<int>> A(N);
		vector<int> B(N);
		for (int i = 0; i < N; ++i) {
			int K{};
			cin >> K;
			A[i].resize(K);
			for (int j = 0; j < K; ++j) {
				cin >> A[i][j];
			}
			cin >> B[i];
		}
		vector<int> C(M + 1);
		for (int i = 1; i <= M; ++i) {
			cin >> C[i];
		}
		int ans{};
		for (int i = 0; i < N; ++i) {
			int minv = 1e9;
			for (int j = 0; j < A[i].size(); ++j) {
				minv = min(minv, C[A[i][j]]);
			}
			ans += minv * B[i];
		}
		cout << ans << "\n";
	}
	return 0;
}
