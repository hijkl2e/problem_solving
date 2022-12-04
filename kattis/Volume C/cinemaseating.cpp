#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, C{};
	cin >> R >> C;
	vector<deque<bool>> A(R + 2, deque<bool>(C + 2));
	int N{};
	cin >> N;
	while (N--) {
		int r{}, c{};
		cin >> r >> c;
		A[r][c] = true;
	}
	vector<int> B(9);
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			if (!A[i][j]) {
				continue;
			}
			int cnt = -1;
			for (int k = -1; k < 2; ++k) {
				for (int l = -1; l < 2; ++l) {
					cnt += A[i + k][j + l];
				}
			}
			++B[cnt];
		}
	}
	for (int i = 0; i < 9; ++i) {
		cout << B[i] << (i == 8 ? "\n" : " ");
	}
	return 0;
}
