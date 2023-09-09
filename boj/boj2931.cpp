#include <bits/stdc++.h>

using namespace std;

bool solve(const string &s, char c) {
	return s.find(c) != -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, C{};
	cin >> R >> C;
	cin.ignore();
	vector<string> A(R);
	for (int i = 0; i < R; ++i) {
		getline(cin, A[i]);
	}
	int ans_x{}, ans_y{};
	char ans_c{};
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (A[i][j] != '.') {
				continue;
			}
			int k{};
			if (i > 0 && solve("|+14", A[i - 1][j])) {
				k |= 1;
			}
			if (i + 1 < R && solve("|+23", A[i + 1][j])) {
				k |= 2;
			}
			if (j > 0 && solve("-+12", A[i][j - 1])) {
				k |= 4;
			}
			if (j + 1 < C && solve("-+34", A[i][j + 1])) {
				k |= 8;
			}
			if (k) {
				ans_x = i + 1;
				ans_y = j + 1;
				ans_c = "xxx|x34xx21x-xx+"[k];
			}
		}
	}
	cout << ans_x << " " << ans_y << " " << ans_c << "\n";
	return 0;
}
