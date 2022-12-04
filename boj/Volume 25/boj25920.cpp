#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

ll solve(ll a, ll b, ll d, ll x) {
	ll c = (a - b) / d;
	ll lo = 0, hi = (x - 1) / b + 1;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		ll e = min(mid, c);
		ll f = max(mid - c, 0LL);
		ll y = e * a - e * (e - 1) / 2 * d + f * b;
		if (y >= x) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	return hi;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, M{}, L{};
	cin >> N >> M >> L;
	vector<ll> A(N);
	vector<ll> B(N);
	vector<ll> D(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i] >> B[i] >> D[i];
	}
	vector<vector<ll>> C(N, vector<ll>(M + 1));
	for (int i = 0; i < N; ++i) {
		for (int j = 1; j <= M; ++j) {
			C[i][j] = solve(A[i], B[i], D[i], j * L);
		}
	}
	vector<ll> dp(M + 1, INF);
	dp[0] = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = M; j >= 0; --j) {
			for (int k = 0; k <= j; ++k) {
				dp[j] = min(dp[j], dp[k] + C[i][j - k]);
			}
		}
	}
	cout << dp[M] << "\n";
	return 0;
}
