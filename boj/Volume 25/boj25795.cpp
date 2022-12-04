#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e5;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, a{}, b{}, c{};
	cin >> N >> a >> b >> c;
	deque<bool> A[16][16];
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= N; ++j) {
			A[i][j].resize(MOD);
		}
	}
	A[0][0][a] = true;
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= i; ++j) {
			for (int k = 0; k < MOD; ++k) {
				if (A[i][j][k]) {
					if (i < N) {
						A[i + 1][j][(k + b) % MOD] = true;
					}
					if (j < i) {
						A[i][j + 1][k * c % MOD] = true;
					}
				}
			}
		}
	}
	int ans{};
	for (int i = MOD - 1; i >= 0; --i) {
		if (A[N][N][i]) {
			ans = i;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
