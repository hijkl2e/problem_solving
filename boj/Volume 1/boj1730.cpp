#include <bits/stdc++.h>

using namespace std;

const int dx[4]{-1, 1, 0, 0};
const int dy[4]{0, 0, -1, 1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	vector<string> A(N, string(N, '\0'));
	string udlr = "UDLR";
	int x{}, y{};
	for (char c : S) {
		int k = udlr.find(c);
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < N && 0 <= ny && ny < N) {
			A[x][y] |= dx[k] ? '|' : '-';
			x = nx, y = ny;
			A[nx][ny] |= dx[k] ? '|' : '-';
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[i][j] == ('|' | '-')) {
				A[i][j] = '+';
			} else if (A[i][j] == '\0') {
				A[i][j] = '.';
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		cout << A[i] << "\n";
	}
	return 0;
}
