#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, R{};
	cin >> N >> R;
	N -= R;
	ll ans{};
	for (ll i = 1; i * i <= N; ++i) {
		if (N % i) {
			continue;
		}
		if (i > R) {
			ans += i;
		}
		if (i * i < N && N / i > R) {
			ans += N / i;
		}
	}
	cout << ans << "\n";
	return 0;
}
