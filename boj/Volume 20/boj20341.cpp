#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(N, vector<int>(3));
	for (int j = 0; j < 3; ++j) {
		for (int i = 0; i < N; ++i) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < N; ++i) {
		sort(A[i].begin(), A[i].end());
		cout << A[i][1] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
