#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 998244353;

vector<vector<int>> G;
vector<int> A;
vector<ll> B;
ll ans{};

void solve(int x, int d) {
	if (G[x].empty()) {
		ans = (ans + B[d]) % MOD;
		return;
	}
	B[d + 1] = (B[d + 1] + 2 * B[d]) % MOD;
	B[d + A[x] + 1] = (B[d + A[x] + 1] - B[d]) % MOD;
	for (int y : G[x]) {
		solve(y, d + 1);
	}
	B[d + 1] = (B[d + 1] - 2 * B[d]) % MOD;
	B[d + A[x] + 1] = (B[d + A[x] + 1] + B[d]) % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	G.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		int p{};
		cin >> p;
		G[p].push_back(i);
	}
	A.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	B.resize(2 * N);
	B[0] = 1, B[1] = -1;
	int r = G[0][0];
	solve(r, 0);
	ans = (ans + MOD) % MOD;
	cout << ans << "\n";
	return 0;
}
