#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int N, M, H;
bool A[31][11];

bool chk() {
	for (int i = 1; i <= N; ++i) {
		int k = i;
		for (int j = 0; j < H; ++j) {
			if (A[j][k]) {
				++k;
			} else if (A[j][k - 1]) {
				--k;
			}
		}
		if (k != i) {
			return false;
		}
	}
	return true;
}

int solve(int n) {
	if (chk()) {
		return n;
	} else if (n == 3) {
		return INF;
	}
	int ret = INF;
	for (int j = 1; j < N; ++j) {
		for (int i = 0; i < H; ++i) {
			if (A[i][j - 1] || A[i][j] || A[i][j + 1]) {
				continue;
			}
			A[i][j] = true;
			ret = min(ret, solve(n + 1));
			A[i][j] = false;
			while (i < H && !A[i][j - 1] && !A[i][j + 1]) {
				++i;
			}
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M >> H;
	while (M--) {
		int a{}, b{};
		cin >> a >> b;
		A[a - 1][b] = true;
	}
	int ans = solve(0);
	cout << (ans == INF ? -1 : ans) << "\n";
	return 0;
}
