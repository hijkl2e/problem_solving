#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

struct point {
	int x{}, y{};
};

bool operator<(point &p1, point &p2) {
	return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

ll pow(ll x, ll y) {
	ll ret = 1;
	while (y) {
		if (y % 2) {
			ret = ret * x % MOD;
		}
		x = x * x % MOD;
		y /= 2;
	}
	return ret;
}

int N, M, K;
vector<point> A;
vector<ll> fact, ifact;
ll ans;

ll nCr(ll n, ll r) {
	return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
}

void solve(int n, int x, int y, int z, ll cnt) {
	if (n == K) {
		cnt = cnt * nCr(N + M - x - y, N - x) % MOD;
		ans += (z ? -1 : 1) * cnt;
		return;
	}
	if (x <= A[n].x && y <= A[n].y) {
		solve(n + 1, A[n].x, A[n].y, z ^ 1, cnt * nCr(A[n].x + A[n].y - x - y, A[n].x - x) % MOD);
	}
	solve(n + 1, x, y, z, cnt);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M >> K;
	A.resize(K);
	for (int i = 0; i < K; ++i) {
		cin >> A[i].x >> A[i].y;
	}
	sort(A.begin(), A.end());
	fact.resize(N + M + 1);
	fact[0] = 1;
	for (int i = 1; i < fact.size(); ++i) {
		fact[i] = i * fact[i - 1] % MOD;
	}
	ifact.resize(N + M + 1);
	ifact[N + M] = pow(fact[N + M], MOD - 2);
	for (int i = N + M - 1; i >= 0; --i) {
		ifact[i] = (i + 1) * ifact[i + 1] % MOD;
	}
	solve(0, 0, 0, 0, 1);
	ans = (ans % MOD + MOD) % MOD;
	cout << ans << "\n";
	return 0;
}
