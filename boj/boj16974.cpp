#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<ll> A, B;

ll solve(ll n, ll x) {
	if (x == 0) {
		return 0;
	} else if (n == 0) {
		return 1;
	} else if (--x <= A[n - 1]) {
		return solve(n - 1, x);
	} else {
		return B[n - 1] + 1 + solve(n - 1, min(x - A[n - 1] - 1, A[n - 1]));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, X{};
	cin >> N >> X;
	A.resize(N + 1);
	B.resize(N + 1);
	A[0] = B[0] = 1;
	for (int i = 1; i <= N; ++i) {
		A[i] = 2 * A[i - 1] + 3;
		B[i] = 2 * B[i - 1] + 1;
	}
	ll ans = solve(N, X);
	cout << ans << "\n";
	return 0;
}
