#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;
const int dx[4]{-1, 1, 0, 0};
const int dy[4]{0, 0, -1, 1};
const string udlr = "UDLR";

vector<string> A;

int convert(int rx, int ry, int bx, int by) {
	return 1000 * rx + 100 * ry + 10 * bx + by;
}

void move(int &rx, int &ry, int &bx, int &by, int d) {
	if (rx == 0) {
		return;
	}
	while (true) {
		rx += dx[d];
		ry += dy[d];
		if (A[rx][ry] == 'O') {
			rx = ry = 0;
			return;
		} else if (A[rx][ry] == '#' || (rx == bx && ry == by)) {
			rx -= dx[d];
			ry -= dy[d];
			return;
		}
	}
}

int move(int z, int d) {
	int rx = z / 1000;
	int ry = z / 100 % 10;
	int bx = z / 10 % 10;
	int by = z % 10;
	move(rx, ry, bx, by, d);
	move(bx, by, rx, ry, d);
	move(rx, ry, bx, by, d);
	return convert(rx, ry, bx, by);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	int rx{}, ry{}, bx{}, by{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == 'R') {
				rx = i, ry = j;
				A[i][j] = '.';
			} else if (A[i][j] == 'B') {
				bx = i, by = j;
				A[i][j] = '.';
			}
		}
	}
	vector<int> D(10001, INF);
	vector<ii> par(10001, {-1, -1});
	queue<int> q;
	int z = convert(rx, ry, bx, by);
	D[z] = 0;
	q.push(z);
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int v = move(u, i);
			if (D[v] == INF) {
				D[v] = D[u] + 1;
				par[v] = {u, i};
				if (v / 100 && v % 100) {
					q.push(v);
				}
			}
		}
	}
	z = 1;
	for (int i = 1; i < 100; ++i) {
		if (D[z] > D[i]) {
			z = i;
		}
	}
	if (D[z] > 10) {
		cout << "-1\n";
		return 0;
	}
	cout << D[z] << "\n";
	string ans;
	while (par[z].first != -1) {
		ans += udlr[par[z].second];
		z = par[z].first;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << "\n";
	return 0;
}
