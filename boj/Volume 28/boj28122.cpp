#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<ll> A;

ll reverse(ll x) {
	ll ret{};
	for (int i = 0; i < 60; ++i) {
		ret = 2 * ret + x % 2;
		x /= 2;
	}
	return ret;
}

int solve(int s, int e, int d) {
	if (d == 0 || s == e) {
		return e - s;
	}
	ll x = (A[s] & ((1LL << 60) - (1LL << d))) | (1LL << (d - 1));
	int p = lower_bound(A.begin() + s, A.begin() + e, x) - A.begin();
	int ret = max(solve(s, p, d - 1), solve(p, e, d - 1));
	ret = min(ret + (d < 60), e - s);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		A[i] = reverse(A[i]);
	}
	sort(A.begin(), A.end());
	cout << solve(0, N, 60) << "\n";
	return 0;
}
