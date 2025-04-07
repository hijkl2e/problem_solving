#include <bits/stdc++.h>

using namespace std;

const int dx[4]{-1, 1, 0, 0};
const int dy[4]{0, 0, -1, 1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<char, int> d2i{
		{'U', 0}, {'D', 1}, {'L', 2}, {'R', 3}
	};
	int R{}, C{};
	for (int tc = 1; cin >> R >> C, R; ++tc) {
		cin.ignore();
		vector<string> A(R);
		for (int i = 0; i < R; ++i) {
			getline(cin, A[i]);
		}
		vector<deque<bool>> B(R, deque<bool>(C));
		int x{}, y{}, cnt{};
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				char c = tolower(A[i][j]);
				if (c == 'b') {
					B[i][j] = true;
					cnt += A[i][j] == 'b';
					A[i][j] = A[i][j] == 'b' ? '.' : '+';
				} else if (c == 'w') {
					x = i, y = j;
					A[i][j] = A[i][j] == 'w' ? '.' : '+';
				}
			}
		}
		string cmd;
		getline(cin, cmd);
		for (char c : cmd) {
			int d = d2i[c];
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (A[nx][ny] == '#') {
				continue;
			} else if (!B[nx][ny]) {
				x = nx, y = ny;
				continue;
			}
			int mx = nx + dx[d];
			int my = ny + dy[d];
			if (A[mx][my] != '#' && !B[mx][my]) {
				B[mx][my] = true;
				B[nx][ny] = false;
				cnt += (A[nx][ny] == '+') - (A[mx][my] == '+');
				x = nx, y = ny;
				if (cnt == 0) {
					break;
				}
			}
		}
		A[x][y] = A[x][y] == '+' ? 'W' : 'w';
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				if (B[i][j]) {
					A[i][j] = A[i][j] == '+' ? 'B' : 'b';
				}
			}
		}
		cout << "Game " << tc << ": " << (cnt ? "in" : "") << "complete\n";
		for (int i = 0; i < R; ++i) {
			cout << A[i] << "\n";
		}
	}
	return 0;
}
