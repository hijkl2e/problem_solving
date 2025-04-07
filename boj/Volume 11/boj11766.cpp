#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, 0, -1, 0};
const int dy[4]{0, 1, 0, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> A(N + 2);
	A[0] = A[N + 1] = string(M + 2, '.');
	for (int i = 1; i <= N; ++i) {
		getline(cin, A[i]);
		A[i] = "." + A[i] + ".";
	}
	vector<vector<int>> B(N + 2, vector<int>(M + 2, -1));
	for (int i = 0; i < N + 2; ++i) {
		for (int j = 0; j < M + 2; ++j) {
			if (A[i][j] == '.') {
				B[i][j] = 0;
			}
		}
	}
	int ring = -1;
	bool flag = true;
	while (flag) {
		flag = false;
		++ring;
		for (int i = 0; i < N + 2; ++i) {
			for (int j = 0; j < M + 2; ++j) {
				if (B[i][j] != ring) {
					continue;
				}
				for (int k = 0; k < 4; ++k) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx == -1 || nx == N + 2 || ny == -1 || ny == M + 2 || B[nx][ny] != -1) {
						continue;
					}
					B[nx][ny] = B[i][j] + 1;
					flag = true;
				}
			}
		}
	}
	int len = ring < 10 ? 2 : 3;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (B[i][j]) {
				cout << setfill('.') << setw(len) << B[i][j];
			} else {
				cout << string(len, '.');
			}
		}
		cout << "\n";
	}
	return 0;
}
