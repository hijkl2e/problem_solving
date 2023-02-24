#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> A;
vector<int> B(2);

void solve(int x, int y, int sz) {
	int cnt{};
	for (int i = 0; i < sz; ++i) {
		for (int j = 0; j < sz; ++j) {
			cnt += A[x + i][y + j];
		}
	}
	if (cnt % (sz * sz) == 0) {
		++B[cnt / (sz * sz)];
		return;
	}
	sz /= 2;
	for (int i = 0; i < 4; ++i) {
		solve(x + i / 2 * sz, y + i % 2 * sz, sz);
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
	cout << B[0] << "\n" << B[1] << "\n";
	return 0;
}
