#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

ii solve(ll P, ll Q) {
	if (P == 1) {
		return {1 % Q, 0};
	}
	auto [x, y] = solve(P / 2, Q);
	ii ret{(x + 2 * y) % Q * x % Q, (x * x + y * y) % Q};
	if (P % 2) {
		ret = {(ret.first + ret.second) % Q, ret.first};
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int P{}, Q{};
		cin >> P >> Q;
		cout << "Case #" << tc << ": " << solve(P, Q).first << "\n";
	}
	return 0;
}
