#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{};
	cin >> N;
	ll ans_x{}, ans_y{};
	ans_x = N * (N + 1) / 2 % MOD;
	ans_x = ans_x * ans_x % MOD;
	ans_x += N * (N + 1) * (2 * N + 1) / 6;
	ans_x %= MOD;
	ans_y = 1;
	for (int i = 1; i <= N; ++i) {
		ans_y = ans_y * i % MOD;
		ans_y = ans_y * i % MOD;
	}
	cout << ans_x << " " << ans_y << "\n";
	return 0;
}
