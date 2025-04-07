#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll solve(ll s, ll e, ll x, int d) {
	ll r = min(1LL << d, e - s);
	if (x == 0) {
		return e - r;
	} else if (x < e - s - r + 1) {
		return solve(s, e - r, x - 1, d - 1);
	} else {
		return solve(e - r + 1, e, x - (e - s - r + 1), d - 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, M{};
	cin >> N >> M;
	vector<ll> P(M);
	for (int i = 0; i < M; ++i) {
		cin >> P[i];
	}
	int d = 63 - __builtin_clzll(N);
	vector<ll> A(M);
	for (int i = 0; i < M; ++i) {
		A[i] = solve(1, N + 1, P[i] - 1, d);
	}
	for (int i = 0; i < M; ++i) {
		cout << A[i] << (i == M - 1 ? "\n" : " ");
	}
	return 0;
}
