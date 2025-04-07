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
	int T{};
	cin >> T;
	while (T--) {
		ll N{}, M{};
		cin >> N >> M;
		vector<ll> A(N / 2 + 1);
		for (int i = 2; i < A.size(); ++i) {
			A[i] = A[i - 1] + phi(i);
		}
		vector<ll> B(N + 1);
		for (int i = 2; i <= N; ++i) {
			B[i] = A[N / i] / (i - 1);
		}
		ll ans{};
		for (int i = N; i > 1; --i) {
			ll cnt = min(M / (i - 1), B[i]);
			M -= cnt * (i - 1);
			ans += cnt * i;
		}
		cout << (M ? -1 : ans) << "\n";
	}
	return 0;
}
