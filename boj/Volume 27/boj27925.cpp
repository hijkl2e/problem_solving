#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int D[2][10][10][10];

int solve(int x, int y) {
	int ret = abs(x - y);
	ret = min(ret, 10 - ret);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	memset(D[0], 0x3f, sizeof D[0]);
	D[0][A[0]][0][0] = D[0][0][A[0]][0] = D[0][0][0][A[0]] = solve(0, A[0]);
	for (int i = 1; i < N; ++i) {
		memset(D[1], 0x3f, sizeof D[1]);
		for (int j = 0; j < 10; ++j) {
			for (int k = 0; k < 10; ++k) {
				for (int l = 0; l < 10; ++l) {
					D[1][A[i]][k][l] = min(D[1][A[i]][k][l], D[0][j][k][l] + solve(j, A[i]));
					D[1][j][A[i]][l] = min(D[1][j][A[i]][l], D[0][j][k][l] + solve(k, A[i]));
					D[1][j][k][A[i]] = min(D[1][j][k][A[i]], D[0][j][k][l] + solve(l, A[i]));
				}
			}
		}
		memcpy(D[0], D[1], sizeof D[1]);
	}
	int ans = INF;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			for (int k = 0; k < 10; ++k) {
				ans = min(ans, D[0][i][j][k]);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
