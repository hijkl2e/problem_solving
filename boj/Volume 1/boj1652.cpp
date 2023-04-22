#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	int ans_x{}, ans_y{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N - 1; ++j) {
			if (A[i][j] == '.' && A[i][j + 1] == '.') {
				++ans_x;
				while (j < N - 1 && A[i][j + 1] == '.') {
					++j;
				}
			}
		}
	}
	for (int j = 0; j < N; ++j) {
		for (int i = 0; i < N - 1; ++i) {
			if (A[i][j] == '.' && A[i + 1][j] == '.') {
				++ans_y;
				while (i < N - 1 && A[i + 1][j] == '.') {
					++i;
				}
			}
		}
	}
	cout << ans_x << " " << ans_y << "\n";
	return 0;
}
