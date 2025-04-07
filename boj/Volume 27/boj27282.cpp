#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

int A[4][3][15];
vector<iii> B[4];
bool C[4][76][76][76];
vector<int> D(3);
vector<int> E(3);

void solve(int x) {
	int y = E[0] + E[1] + E[2];
	if (y == 15) {
		B[x].push_back({D[0], D[1], D[2]});
		return;
	}
	for (int i = 0; i < 3; ++i) {
		if (E[i] == 5) {
			continue;
		}
		D[i] += A[x][i][y];
		++E[i];
		solve(x);
		D[i] -= A[x][i][y];
		--E[i];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 15; ++k) {
				cin >> A[i][j][k];
			}
		}
	}
	for (int i = 0; i < 4; ++i) {
		solve(i);
	}
	for (int i = 1; i < 4; ++i) {
		for (auto &[a, b, c] : B[i]) {
			C[i][a][b][c] = true;
		}
		for (int j = 75; j >= 0; --j) {
			for (int k = 75; k >= 0; --k) {
				for (int l = 75; l >= 0; --l) {
					if (C[i][j][k][l]) {
						C[i][max(j - 1, 0)][k][l] = true;
						C[i][j][max(k - 1, 0)][l] = true;
						C[i][j][k][max(l - 1, 0)] = true;
					}
				}
			}
		}
	}
	bool yes{};
	for (auto &[a, b, c] : B[0]) {
		yes = true;
		for (int i = 1; i < 4; ++i) {
			if (C[i][a][b][0] || C[i][0][b][c] || C[i][a][0][c]) {
				yes = false;
			}
		}
		for (int i = 1; i < 4; ++i) {
			for (int j = 1; j < 4; ++j) {
				if (i == j) {
					continue;
				}
				if ((C[i][a][0][0] && (C[j][0][b][0] || C[j][0][0][c]))
						|| (C[i][0][b][0] && (C[j][0][0][c] || C[j][a][0][0]))
						|| (C[i][0][0][c] && (C[j][a][0][0] || C[j][0][b][0]))) {
					yes = false;
				}
			}
		}
		if (yes) {
			break;
		}
	}
	cout << (yes ? "YES" : "NO") << "\n";
	return 0;
}
