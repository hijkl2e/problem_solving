#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> A, B;

bool solve(int K) {
	for (int i = N - 1; i >= 0; --i) {
		for (int j = M - 1; j >= 0; --j) {
			B[i][j] = A[i][j] >= K;
			if (B[i][j] && i < N - 1 && j < M - 1) {
				B[i][j] = min({B[i][j + 1], B[i + 1][j], B[i + 1][j + 1]}) + 1;
			}
			if (B[i][j] >= K) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		cin >> N >> M;
		A.assign(N, vector<int>(M));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				cin >> A[i][j];
			}
		}
		B.assign(N, vector<int>(M));
		int lo = 1, hi = N + 1;
		while (lo + 1 < hi) {
			int mid = (lo + hi) / 2;
			if (solve(mid)) {
				lo = mid;
			} else {
				hi = mid;
			}
		}
		cout << lo << "\n";
	}
	return 0;
}
