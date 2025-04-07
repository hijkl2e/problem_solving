#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int N, M, L;
vector<string> A;
vector<char> B;
vector<vector<int>> dp;
vector<deque<bool>> vst;

int solve(int x, int y) {
	if (vst[x][y]) {
		return -1;
	} else if (dp[x][y]) {
		return dp[x][y];
	}
	vst[x][y] = true;
	dp[x][y] = 1;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny] == B[A[x][y] - 'A']) {
			int res = solve(nx, ny);
			if (res == -1) {
				vst[x][y] = false;
				return dp[x][y] = -1;
			}
			dp[x][y] = max(dp[x][y], res + 1);
		}
	}
	vst[x][y] = false;
	return dp[x][y];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M >> L;
	cin.ignore();
	string S;
	getline(cin, S);
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	B.resize(26);
	for (int i = 0; i < L; ++i) {
		B[S[i] - 'A'] = S[(i + 1) % L];
	}
	dp.assign(N, vector<int>(M));
	vst.assign(N, deque<bool>(M));
	solve(0, 0);
	if (dp[0][0] < L) {
		cout << "-1\n";
		return 0;
	}
	int x{}, y{};
	while (A[x][y] != S[L - 1] || dp[x][y] > L) {
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny] == B[A[x][y] - 'A']
					&& dp[nx][ny] == dp[x][y] - 1) {
				x = nx, y = ny;
				break;
			}
		}
	}
	cout << dp[0][0] / L << "\n";
	cout << x + 1 << " " << y + 1 << "\n";
	return 0;
}
