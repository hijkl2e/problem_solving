#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int N, K, ans;
vector<int> C;

void solve(int n, int x, vector<vector<int>> &A, vector<vector<int>> &B) {
	ans = max(ans, x);
	if (n == K) {
		return;
	}
	for (int i = 0; i < N; ++i) {
		int j{};
		while (j < N && A[i][j] == 0) {
			++j;
		}
		if (j == N) {
			continue;
		}
		vector<vector<int>> D = A;
		vector<vector<int>> E = B;
		int y = x;
		if (D[i][j] < 10) {
			E[i][j] += C[n];
			if (E[i][j] >= D[i][j]) {
				y += D[i][j];
				for (int k = 0; k < 4; ++k) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (0 <= nx && nx < N && 0 <= ny && ny < N && D[nx][ny] == 0) {
						D[nx][ny] = D[i][j] / 4;
					}
				}
				D[i][j] = E[i][j] = 0;
			}
		} else {
			y += D[i][j];
			D[i][j] = 0;
		}
		solve(n + 1, y, D, E);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> K;
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	vector<vector<int>> B(N, vector<int>(N));
	C.resize(K);
	for (int i = 0; i < K; ++i) {
		cin >> C[i];
	}
	solve(0, 0, A, B);
	cout << ans << "\n";
	return 0;
}
