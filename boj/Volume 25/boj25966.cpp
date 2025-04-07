#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, Q{};
	cin >> N >> M >> Q;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		B[i] = i;
	}
	while (Q--) {
		int q{}, a{}, b{}, c{};
		cin >> q >> a >> b;
		if (q == 0) {
			cin >> c;
			A[B[a]][b] = c;
		} else {
			swap(B[a], B[b]);
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << A[B[i]][j] << (j == M - 1 ? "\n" : " ");
		}
	}
	return 0;
}
