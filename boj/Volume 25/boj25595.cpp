#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(N, vector<int>(N));
	int sx{}, sy{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
			if (A[i][j] == 2) {
				sx = i, sy = j;
			}
		}
	}
	bool yes = true;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[i][j] == 1 && (sx + sy + i + j) % 2 == 0) {
				yes = false;
			}
		}
	}
	cout << (yes ? "Lena" : "Kiriya") << "\n";
	return 0;
}
