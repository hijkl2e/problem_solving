#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> A(N + 1, vector<int>(N + 1));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> A[i][j];
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			A[i][j] += A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1];
		}
	}
	while (M--) {
		int x1{}, y1{}, x2{}, y2{};
		cin >> x1 >> y1 >> x2 >> y2;
		cout << A[x2][y2] - A[x1 - 1][y2] - A[x2][y1 - 1] + A[x1 - 1][y1 - 1] << "\n";
	}
	return 0;
}
