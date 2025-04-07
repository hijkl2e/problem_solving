#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> x(N + 1);
	vector<ll> y(N + 1);
	for (int i = 0; i < N; ++i) {
		cin >> x[i] >> y[i];
	}
	x[N] = x[0];
	y[N] = y[0];
	ll ans{};
	for (int i = 0; i < N; ++i) {
		ans += x[i] * y[i + 1] - y[i] * x[i + 1];
	}
	ans = abs(ans);
	cout << ans / 2 << "." << (ans % 2 ? 5 : 0) << "\n";
	return 0;
}
