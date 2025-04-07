#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, C{};
	cin >> R >> C;
	vector<vector<int>> A(R, vector<int>(C));
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> A[i][j];
		}
	}
	string ans;
	if (R % 2) {
		for (int i = 0; i < R; ++i) {
			ans += string(C - 1, i % 2 ? 'L' : 'R');
			ans += i == R - 1 ? "" : "D";
		}
		cout << ans << "\n";
		return 0;
	} else if (C % 2) {
		for (int i = 0; i < C; ++i) {
			ans += string(R - 1, i % 2 ? 'U' : 'D');
			ans += i == C - 1 ? "" : "R";
		}
		cout << ans << "\n";
		return 0;
	}
	int x = 0, y = 1;
	for (int i = 0; i < R; ++i) {
		for (int j = i % 2 ? 0 : 1; j < C; j += 2) {
			if (A[x][y] > A[i][j]) {
				x = i, y = j;
			}
		}
	}
	for (int i = 0; i < x / 2; ++i) {
		ans += string(C - 1, 'R') + "D" + string(C - 1, 'L') + "D";
	}
	for (int i = 0; i < y / 2; ++i) {
		ans += "DRUR";
	}
	ans += x % 2 ? "RD" : "DR";
	for (int i = y / 2 + 1; i < C / 2; ++i) {
		ans += "RURD";
	}
	for (int i = x / 2 + 1; i < R / 2; ++i) {
		ans += "D" + string(C - 1, 'L') + "D" + string(C - 1, 'R');
	}
	cout << ans << "\n";
	return 0;
}
