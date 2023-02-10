#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

const ll MOD = 1e9 + 7;

ii solve(int N) {
	if (N == 1) {
		return {1, 0};
	}
	auto [x, y] = solve(N / 2);
	ii ret{x * (x + 2 * y) % MOD, (x * x + y * y) % MOD};
	if (N % 2) {
		ret = {(ret.first + ret.second) % MOD, ret.first};
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cout << solve(N).first << " " << N - 2 << "\n";
	return 0;
}
