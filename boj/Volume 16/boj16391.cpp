#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	ll x{};
	for (int i = 0; i < N; ++i) {
		char c{};
		cin >> c;
		x = 2 * x + (c == 'Z');
	}
	ll ans = (1LL << N) - x - 1;
	cout << ans << "\n";
	return 0;
}
