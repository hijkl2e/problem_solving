#include <bits/stdc++.h>

using namespace std;

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
	int x{}, y{};
	cin >> x >> y;
	--x, --y;
	for (int i = 0; i < 2 * R; ++i) {
		for (int j = 0; j < 2 * C; ++j) {
			char c = A[i < R ? i : (2 * R - i - 1)][j < C ? j : (2 * C - j - 1)];
			if (i == x && j == y) {
				c = c == '.' ? '#' : '.';
			}
			cout << c;
		}
		cout << "\n";
	}
	return 0;
}
