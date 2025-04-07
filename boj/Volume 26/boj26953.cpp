#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll M{}, B{};
	cin >> M >> B;
	vector<ll> A(M + 1);
	A[1] = 1;
	for (int i = 2; i <= M; ++i) {
		A[i] = A[i - 1] + 2 * phi(i);
	}
	ll ans{};
	for (int i = 1; i <= M; ++i) {
		if (B % i == 0) {
			ans += A[M / i];
		}
	}
	ans -= M;
	cout << ans << "\n";
	return 0;
}
