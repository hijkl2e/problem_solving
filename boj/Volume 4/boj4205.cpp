#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int N;
int D[21][21];
int dp[18][2][1 << 18];
int A[2][1 << 18];

int solve(int u, int g, int x) {
	int &val = dp[u][g][x];
	if (val != INF) {
		return val;
	} else if (x == 0) {
		return val = D[u][N + g];
	}
	for (int i = 0; i < N; ++i) {
		if (x & (1 << i)) {
			val = min(val, D[u][i] + solve(i, g, x & ~(1 << i)));
		}
	}
	return val;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{};
	for (int tc = 1; cin >> N >> M; ++tc) {
		memset(D, 0x3f, sizeof D);
		for (int i = 0; i < N; ++i) {
			D[i][i] = 0;
		}
		while (M--) {
			int u{}, v{}, t{};
			cin >> u >> v >> t;
			u = u == 0 ? N - 2 : u == N - 2 ? 0 : u;
			v = v == 0 ? N - 2 : v == N - 2 ? 0 : v;
			D[u][v] = D[v][u] = t;
		}
		for (int k = 0; k < N; ++k) {
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
				}
			}
		}
		N -= 2;
		int h = N / 2;
		memset(dp, 0x3f, sizeof dp);
		memset(A, 0x3f, sizeof A);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < (1 << N); ++j) {
				if (__builtin_popcount(j) != h || (j & (1 << i))) {
					continue;
				}
				A[0][j] = min(A[0][j], solve(i, 0, j) + solve(i, 1, ((1 << N) - 1) & ~(j | (1 << i))));
				A[1][j] = min(A[1][j], solve(i, 1, j) + solve(i, 0, ((1 << N) - 1) & ~(j | (1 << i))));
			}
		}
		int ans = INF;
		for (int i = 0; i < (1 << N); ++i) {
			ans = min(ans, A[0][i] + A[1][i]);
		}
		cout << "Case " << tc << ": " << ans << "\n";
	}
	return 0;
}
