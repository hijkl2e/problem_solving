#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> A;
vector<int> B(3);

void solve(int x, int y, int sz) {
	int cnt{};
	for (int i = 0; i < sz; ++i) {
		for (int j = 0; j < sz; ++j) {
			if (A[x + i][y + j] == A[x][y]) {
				++cnt;
			}
		}
	}
	if (cnt == sz * sz) {
		++B[A[x][y] + 1];
		return;
	}
	sz /= 3;
	for (int i = 0; i < 9; ++i) {
		solve(x + i / 3 * sz, y + i % 3 * sz, sz);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	A.assign(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	solve(0, 0, N);
	for (int i = 0; i < 3; ++i) {
		cout << B[i] << "\n";
	}
	return 0;
}
