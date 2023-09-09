#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> A(N, vector<int>(N));
	vector<int> B(2 * N);
	while (M--) {
		int a{}, b{}, c{};
		cin >> a >> b >> c;
		++B[a], ++B[a + b];
	}
	partial_sum(B.begin(), B.end(), B.begin());
	for (int i = 0; i < N; ++i) {
		A[i][0] = B[N - i - 1] + 1;
		A[0][i] = B[N + i - 1] + 1;
	}
	for (int i = 1; i < N; ++i) {
		for (int j = 1; j < N; ++j) {
			A[i][j] = max({A[i][j - 1], A[i - 1][j - 1], A[i - 1][j]});
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << A[i][j] << (j == N - 1 ? "\n" : " ");
		}
	}
	return 0;
}
