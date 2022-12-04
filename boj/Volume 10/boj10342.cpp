#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, 0, -1, 0};
const int dy[4]{0, -1, 0, 1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int W{}, L{};
	for (int tc = 1; cin >> W >> L, W; ++tc) {
		cin.ignore();
		vector<string> A(L);
		for (int i = 0; i < L; ++i) {
			getline(cin, A[i]);
		}
		int x{}, y{}, d{};
		for (int i = 0; i < L; ++i) {
			for (int j = 0; j < W; ++j) {
				if (A[i][j] == '*') {
					x = i;
					y = j;
					d = i == 0 ? 0 : j == W - 1 ? 1 : i == L - 1 ? 2 : 3;
					
				}
			}
		}
		while (true) {
			x += dx[d];
			y += dy[d];
			if (A[x][y] == '/') {
				d = (d ^ 1) % 4;
			} else if (A[x][y] == '\\') {
				d = (((d + 3) ^ 1) + 1) % 4;
			} else if (A[x][y] == 'x') {
				A[x][y] = '&';
				break;
			}
		}
		cout << "HOUSE " << tc << "\n";
		for (int i = 0; i < L; ++i) {
			cout << A[i] << "\n";
		}
	}
	return 0;
}
