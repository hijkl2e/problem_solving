#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	if (N * M % 2) {
		cout << "-1\n";
		return 0;
	}
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	int cnt{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cnt += A[i][j];
		}
	}
	if (cnt % 2) {
		cout << "-1\n";
		return 0;
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			for (int k = 0; k < 4; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (0 <= nx && nx < N && 0 <= ny && ny < M && A[i][j] == A[nx][ny]) {
					cout << "1\n";
					cout << i + 1 << " " << j + 1 << " " << nx + 1 << " " << ny + 1 << "\n";
					A[i][j] = A[nx][ny] = -1;
					i = N, j = M;
					break;
				}
			}
		}
	}
	vector<vector<ii>> B(2);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] != -1) {
				B[A[i][j]].push_back({i + 1, j + 1});
			}
		}
	}
	if (B[0].size() + B[1].size() == N * M) {
		cout << "-1\n";
		return 0;
	}
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < B[i].size(); j += 2) {
			cout << B[i][j].first << " " << B[i][j].second << " ";
			cout << B[i][j + 1].first << " " << B[i][j + 1].second << "\n";
		}
	}
	return 0;
}
