#include <bits/stdc++.h>

using namespace std;

const int dx[8]{-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8]{-1, 0, 1, 1, 1, 0, -1, -1};

int N, M;
vector<string> A;

bool solve(string &S, int n, int x, int y, int d) {
	if (n == S.size()) {
		return true;
	} else if (x == -1 || x == N || y == -1 || y == M || tolower(S[n]) != tolower(A[x][y])) {
		return false;
	} else {
		return solve(S, n + 1, x + dx[d], y + dy[d], d);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		cin >> N >> M;
		cin.ignore();
		A.resize(N);
		for (int i = 0; i < N; ++i) {
			getline(cin, A[i]);
		}
		int K{};
		cin >> K;
		cin.ignore();
		while (K--) {
			string S;
			getline(cin, S);
			int ans_x = N, ans_y = M;
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < M; ++j) {
					for (int k = 0; k < 8; ++k) {
						if (solve(S, 0, i, j, k)) {
							ans_x = i + 1, ans_y = j + 1;
							i = j = k = 51;
							break;
						}
					}
				}
			}
			cout << ans_x << " " << ans_y << "\n";
		}
		if (T) {
			cout << "\n";
		}
	}
	return 0;
}
