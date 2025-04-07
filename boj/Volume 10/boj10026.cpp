#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int N;
vector<string> A;
vector<deque<bool>> vst;

void dfs(int x, int y, bool f) {
	vst[x][y] = true;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < N && 0 <= ny && ny < N && !vst[nx][ny]
				&& (A[x][y] == A[nx][ny] || (f && A[x][y] != 'B' && A[nx][ny] != 'B'))) {
			dfs(nx, ny, f);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	cin.ignore();
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	vector<int> B(2);
	for (int k = 0; k < 2; ++k) {
		vst.assign(N, deque<bool>(N));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (!vst[i][j]) {
					dfs(i, j, k);
					++B[k];
				}
			}
		}
	}
	cout << B[0] << " " << B[1] << "\n";
	return 0;
}
