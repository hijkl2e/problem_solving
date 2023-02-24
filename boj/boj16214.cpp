#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll pow(ll x, ll y, ll mod) {
	ll ret = 1;
	while (y) {
		if (y % 2) {
			ret = ret * x % mod;
		}
		x = x * x % mod;
		y /= 2;
	}
	return ret;
}

int phi(int x) {
	int ret = 1;
	for (int i = 2; i * i <= x; ++i) {
		int y = 1;
		while (x % i == 0) {
			x /= i;
			y *= i;
		}
		ret *= y - y / i;
	}
	if (x > 1) {
		ret *= x - 1;
	}
	return ret;
}

int solve(int N, int M) {
	if (M == 1) {
		return 0;
	}
	int p = phi(M);
	return pow(N, p + solve(N, p), M);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		cout << solve(N, M) << "\n";
	}
	return 0;
}
