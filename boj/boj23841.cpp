#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] != '.') {
				A[i][M - j - 1] = A[i][j];
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		cout << A[i] << "\n";
	}
	return 0;
}
