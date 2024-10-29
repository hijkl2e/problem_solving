#include <bits/stdc++.h>

using namespace std;

const int dx[10]{0, 1, 1, 1, 0, 0, 0, -1, -1, -1};
const int dy[10]{0, -1, 0, 1, -1, 0, 1, -1, 0, 1};

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
	int ix{}, iy{};
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (A[i][j] == 'I') {
				ix = i, iy = j;
			}
		}
	}
	string S;
	getline(cin, S);
	int X{};
	for (char c : S) {
		++X;
		int d = c - '0';
		ix += dx[d];
		iy += dy[d];
		if (A[ix][iy] == 'R') {
			cout << "kraj " << X << "\n";
			return 0;
		}
		vector<string> B(R, string(C, '.'));
		B[ix][iy] = 'I';
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				if (A[i][j] == 'R') {
					int nx = i + (i < ix ? 1 : i > ix ? -1 : 0);
					int ny = j + (j < iy ? 1 : j > iy ? -1 : 0);
					if (B[nx][ny] == 'I') {
						cout << "kraj " << X << "\n";
						return 0;
					} else if (B[nx][ny] == '.') {
						B[nx][ny] = 'R';
					} else if (B[nx][ny] == 'R') {
						B[nx][ny] = 'r';
					}
				}
			}
		}
		A = B;
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				if (A[i][j] == 'r') {
					A[i][j] = '.';
				}
			}
		}
	}
	for (int i = 0; i < R; ++i) {
		cout << A[i] << "\n";
	}
	return 0;
}
