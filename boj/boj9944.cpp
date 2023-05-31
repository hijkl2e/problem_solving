#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;
const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int N, M, ans;
vector<string> A;

void solve(int x, int y, int u, int v) {
	if (u == N * M) {
		ans = min(ans, v);
		return;
	}
	for (int i = 0; i < 4; ++i) {
		int nx = x, ny = y, k{};
		while (true) {
			nx += dx[i];
			ny += dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny] == '.') {
				++k;
			} else {
				break;
			}
		}
		if (k == 0) {
			continue;
		}
		for (int l = 0; l < 2; ++l) {
			nx = x, ny = y;
			for (int j = 0; j < k; ++j) {
				nx += dx[i];
				ny += dy[i];
				A[nx][ny] = l ? '.' : '*';
			}
			if (l == 0) {
				solve(nx, ny, u + k, v + 1);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int tc = 1; cin >> N >> M; ++tc) {
		cin.ignore();
		A.resize(N);
		for (int i = 0; i < N; ++i) {
			getline(cin, A[i]);
		}
		int cnt = 1;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (A[i][j] == '*') {
					++cnt;
				}
			}
		}
		ans = INF;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (A[i][j] == '.') {
					A[i][j] = '*';
					solve(i, j, cnt, 0);
					A[i][j] = '.';
				}
			}
		}
		cout << "Case " << tc << ": " << (ans == INF ? -1 : ans) << "\n";
	}
	return 0;
}
