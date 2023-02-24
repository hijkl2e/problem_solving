#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, B{};
	cin >> N >> B;
	vector<ll> x(N);
	vector<ll> y(N);
	for (int i = 0; i < N; ++i) {
		cin >> x[i] >> y[i];
	}
	ll n = accumulate(y.begin(), y.end(), 0LL) - N * B;
	ll d = accumulate(x.begin(), x.end(), 0LL);
	if (d) {
		ll g = gcd(n, d);
		n /= g, d /= g;
		if (d < 0) {
			n *= -1, d *= -1;
		}
		cout << n;
		if (d > 1) {
			cout << "/" << d;
		}
		cout << "\n";
	} else {
		cout << "EZPZ\n";
	}
	return 0;
}
