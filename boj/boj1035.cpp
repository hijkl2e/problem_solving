#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int board_to_int(vector<string> &A) {
	int ret{};
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			ret = 2 * ret + (A[i][j] == '*');
		}
	}
	return ret;
}

void int_to_board(int x, vector<string> &A) {
	for (int i = 4; i >= 0; --i) {
		for (int j = 4; j >= 0; --j) {
			A[i][j] = x % 2 ? '*' : '.';
			x /= 2;
		}
	}
}

bool solve(int u, vector<string> &A) {
	int n = __builtin_popcount(u);
	int_to_board(u, A);
	queue<ii> q;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (A[i][j] == '*') {
				A[i][j] = '.';
				q.push({i, j});
				i = 5;
				break;
			}
		}
	}
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && A[nx][ny] == '*') {
				A[nx][ny] = '.';
				q.push({nx, ny});
			}
		}
		--n;
	}
	return n == 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> A(5);
	for (int i = 0; i < 5; ++i) {
		getline(cin, A[i]);
	}
	int z = board_to_int(A);
	map<int, int> D;
	D[z] = 0;
	queue<int> q;
	q.push(z);
	int ans{};
	while (q.size()) {
		int u = q.front(); q.pop();
		if (solve(u, A)) {
			ans = D[u];
			break;
		}
		int_to_board(u, A);
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (A[i][j] == '.') {
					continue;
				}
				for (int k = 0; k < 4; ++k) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && A[nx][ny] == '.') {
						swap(A[i][j], A[nx][ny]);
						int v = board_to_int(A);
						if (D.insert({v, D[u] + 1}).second) {
							q.push(v);
						}
						swap(A[i][j], A[nx][ny]);
					}
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
