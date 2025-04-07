#include <bits/stdc++.h>

using namespace std;

const int dx[8]{-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8]{-1, 0, 1, 1, 1, 0, -1, -1};

int N, M, K;
vector<string> A;
map<string, int> B;

void solve(int x, int y, string S) {
	++B[S];
	if (S.size() == 5) {
		return;
	}
	for (int i = 0; i < 8; ++i) {
		int nx = (x + dx[i] + N) % N;
		int ny = (y + dy[i] + M) % M;
		solve(nx, ny, S + A[nx][ny]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M >> K;
	cin.ignore();
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			solve(i, j, string(1, A[i][j]));
		}
	}
	while (K--) {
		string S;
		getline(cin, S);
		cout << B[S] << "\n";
	}
	return 0;
}
