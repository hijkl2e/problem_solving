#include <bits/stdc++.h>

using namespace std;

const int dx[8]{-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8]{-1, 0, 1, 1, 1, 0, -1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	vector<string> B(N, string(N, '*'));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[i][j] != '.') {
				continue;
			}
			int cnt{};
			for (int k = 0; k < 8; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (0 <= nx && nx < N && 0 <= ny && ny < N && A[nx][ny] != '.') {
					cnt += A[nx][ny] - '0';
				}
			}
			B[i][j] = cnt < 10 ? (cnt + '0') : 'M';
		}
	}
	for (auto &s : B) {
		cout << s << "\n";
	}
	return 0;
}
