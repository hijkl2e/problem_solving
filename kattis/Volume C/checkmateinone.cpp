#include <bits/stdc++.h>

using namespace std;

bool solve(int Rx, int Ry, int Kx, int Ky, int kx, int ky) {
	if (kx != 0 && kx != 7 && ky != 0 && ky != 7) {
		return false;
	}
	if (kx == 0) {
		return solve(7 - Rx, Ry, 7 - Kx, Ky, 7 - kx, ky);
	} else if (ky == 0) {
		return solve(Rx, 7 - Ry, Kx, 7 - Ky, kx, 7 - ky);
	} else if (ky != 7) {
		return solve(Ry, Rx, Ky, Kx, ky, kx);
	}
	if (kx == 7) {
		return (Ky == 5 && (Kx == 7 || Kx == 6) && Rx <= 5)
				|| (Kx == 5 && (Ky == 7 || Ky == 6) && Ry <= 5);
	} else {
		return Kx == kx && Ky == 5 && abs(Rx - kx) >= 2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> grid(8);
	for (int i = 0; i < 8; ++i) {
		getline(cin, grid[i]);
	}
	int Rx{}, Ry{}, Kx{}, Ky{}, kx{}, ky{};
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (grid[i][j] == 'R') {
				Rx = i;
				Ry = j;
			} else if (grid[i][j] == 'K') {
				Kx = i;
				Ky = j;
			} else if (grid[i][j] == 'k') {
				kx = i;
				ky = j;
			}
		}
	}
	cout << (solve(Rx, Ry, Kx, Ky, kx, ky) ? "Yes" : "No") << "\n";
	return 0;
}
