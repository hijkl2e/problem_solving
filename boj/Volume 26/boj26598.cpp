#include <bits/stdc++.h>

using namespace std;

const int dx[4]{-1, 0, 1, 0};
const int dy[4]{0, 1, 0, -1};

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
	bool yes = true;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			for (int k = 0; k < 4; ++k) {
				int nx1 = i + dx[k];
				int ny1 = j + dy[k];
				if (0 <= nx1 && nx1 < N && 0 <= ny1 && ny1 < M && A[i][j] == A[nx1][ny1]) {
					int nx2 = i + dx[(k + 1) % 4];
					int ny2 = j + dy[(k + 1) % 4];
					if (0 <= nx2 && nx2 < N && 0 <= ny2 && ny2 < M && A[i][j] == A[nx2][ny2]) {
						int nx3 = nx1 + nx2 - i;
						int ny3 = ny1 + ny2 - j;
						yes &= A[i][j] == A[nx3][ny3];
					}
				}
			}
		}
	}
	cout << (yes ? "dd" : "BaboBabo") << "\n";
	return 0;
}
