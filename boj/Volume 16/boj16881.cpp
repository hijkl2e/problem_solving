#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		int x{};
		for (int j = M - 1; j >= 0; --j) {
			x = A[i][j] - (A[i][j] <= x);
		}
		ans ^= x;
	}
	cout << (ans ? "koosaga" : "cubelover") << "\n";
	return 0;
}
