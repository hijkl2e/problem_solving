#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int W{}, H{}, N{};
		cin >> W >> H >> N;
		cin.ignore();
		vector<string> P1(H);
		vector<string> P2(H);
		for (int i = H - 1; i >= 0; --i) {
			getline(cin, P1[i]);
		}
		for (int i = H - 1; i >= 0; --i) {
			getline(cin, P2[i]);
		}
		int p1{}, p2{};
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				if (P1[i][j] == '#') {
					++p1;
				}
				if (P2[i][j] == '#') {
					++p2;
				}
			}
		}
		int turn = 1;
		int winner{};
		while (N--) {
			int x{}, y{};
			cin >> y >> x;
			if (winner) {
				continue;
			}
			bool flag{};
			if (turn) {
				if (P2[x][y] == '#') {
					P2[x][y] = '_';
					flag = --p2;
				}
			} else {
				if (P1[x][y] == '#') {
					P1[x][y] = '_';
					flag = --p1;
				}
			}
			if (!flag) {
				turn ^= 1;
				if (turn) {
					if (p1 && !p2) {
						winner = 1;
					} else if (!p1 && p2) {
						winner = 2;
					}
				}
			}
		}
		if (winner == 1) {
			cout << "player one wins\n";
		} else if (winner == 2) {
			cout << "player two wins\n";
		} else {
			cout << "draw\n";
		}
	}
	return 0;
}
