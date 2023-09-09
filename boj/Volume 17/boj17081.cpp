#include <bits/stdc++.h>

using namespace std;

const int xd[4]{0, 0, -1, 1};
const int yd[4]{-1, 1, 0, 0};

struct Monster {
	string s;
	int w{}, a{}, h{}, e{};
};

struct Item {
	char t{};
	string s;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	string S;
	getline(cin, S);
	int sx{}, sy{}, K{}, L{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == '@') {
				sx = i, sy = j;
				A[i][j] = '.';
			} else if (A[i][j] == '&' || A[i][j] == 'M') {
				++K;
			} else if (A[i][j] == 'B') {
				++L;
			}
		}
	}
	vector<vector<Monster>> B(N, vector<Monster>(M));
	while (K--) {
		int r{}, c{};
		cin >> r >> c;
		--r, --c;
		auto &[s, w, a, h, e] = B[r][c];
		cin >> s >> w >> a >> h >> e;
	}
	vector<vector<Item>> C(N, vector<Item>(M));
	while (L--) {
		int r{}, c{};
		cin >> r >> c;
		--r, --c;
		auto &[t, s] = C[r][c];
		cin >> t >> s;
	}
	int T{}, lv = 1, hp = 20, att = 2, def = 2, exp{};
	bool hr{}, re{}, co{}, ex{}, dx{}, hu{}, cu{};
	int x = sx, y = sy;
	for (; T < S.size() && A[x][y] != 'M' && hp > 0; ++T) {
		int d = S[T] == 'L' ? 0 : S[T] == 'R' ? 1 : S[T] == 'U' ? 2 : 3;
		int nx = x + xd[d];
		int ny = y + yd[d];
		if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny] != '#') {
			x = nx, y = ny;
		}
		if (A[x][y] == '&' || A[x][y] == 'M') {
			if (A[x][y] == 'M' && hu) {
				hp = 5 * lv + 15;
			}
			int fa = max(1, (co ? dx ? 3 : 2 : 1) * att - B[x][y].a);
			int cnt{};
			if (B[x][y].h - fa > 0) {
				cnt = (B[x][y].h - fa - 1) / max(1, att - B[x][y].a) - (A[x][y] == 'M' && hu) + 1;
			}
			hp -= cnt * max(1, B[x][y].w - def);
			if (hp > 0) {
				if (A[x][y] == '&') {
					A[x][y] = '.';
				}
				if (hr) {
					hp = min(hp + 3, 5 * lv + 15);
				}
				exp += (ex ? 12 : 10) * B[x][y].e / 10;
				if (exp >= 5 * lv) {
					hp = 5 * ++lv + 15;
					att += 2, def += 2;
					exp = 0;
				}
			}
		} else if (A[x][y] == '^') {
			hp -= dx ? 1 : 5;
		} else if (A[x][y] == 'B') {
			if (C[x][y].t == 'W') {
				att = 2 * lv + stoi(C[x][y].s);
			} else if (C[x][y].t == 'A') {
				def = 2 * lv + stoi(C[x][y].s);
			} else if (hr + re + co + ex + dx + hu + cu < 4) {
				if (C[x][y].s == "HR") {
					hr = true;
				} else if (C[x][y].s == "RE") {
					re = true;
				} else if (C[x][y].s == "CO") {
					co = true;
				} else if (C[x][y].s == "EX") {
					ex = true;
				} else if (C[x][y].s == "DX") {
					dx = true;
				} else if (C[x][y].s == "HU") {
					hu = true;
				} else {
					cu = true;
				}
			}
			A[x][y] = '.';
		}
		if (hp <= 0 && re) {
			hp = 5 * lv + 15;
			x = sx, y = sy;
			re = false;
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << (hp > 0 && x == i && y == j ? '@' : A[i][j]);
		}
		cout << "\n";
	}
	cout << "Passed Turns : " << T << "\n";
	cout << "LV : " << lv << "\n";
	cout << "HP : " << max(hp, 0) << "/" << (5 * lv + 15) << "\n";
	cout << "ATT : " << (2 * lv) << "+" << (att - 2 * lv) << "\n";
	cout << "DEF : " << (2 * lv) << "+" << (def - 2 * lv) << "\n";
	cout << "EXP : " << exp << "/" << (5 * lv) << "\n";
	if (A[x][y] == 'M' && hp > 0) {
		cout << "YOU WIN!\n";
	} else if (hp <= 0) {
		cout << "YOU HAVE BEEN KILLED BY ";
		if (A[x][y] == '&' || A[x][y] == 'M') {
			cout << B[x][y].s << "..\n";
		} else {
			cout << "SPIKE TRAP..\n";
		}
	} else {
		cout << "Press any key to continue.\n";
	}
	return 0;
}
