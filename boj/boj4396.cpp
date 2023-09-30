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
	vector<string> B(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	for (int i = 0; i < N; ++i) {
		getline(cin, B[i]);
	}
	bool flag{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[i][j] == '*' && B[i][j] == 'x') {
				flag = true;
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[i][j] == '*') {
				if (flag) {
					B[i][j] = '*';
				}
				continue;
			} else if (B[i][j] == '.') {
				continue;
			}
			int cnt{};
			for (int k = 0; k < 8; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (0 <= nx && nx < N && 0 <= ny && ny < N && A[nx][ny] == '*') {
					++cnt;
				}
			}
			B[i][j] = cnt + '0';
		}
	}
	for (auto &s : B) {
		cout << s << "\n";
	}
	return 0;
}
