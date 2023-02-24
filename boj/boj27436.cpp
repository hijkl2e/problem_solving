#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int solve(__int128 N) {
	if (N == 1) {
		return 1;
	}
	N = 12 * N - 15;
	__int128 lo = 3, hi = 12e9;
	while (lo + 1 < hi) {
		__int128 mid = (lo + hi) / 2;
		if (mid * mid > N) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	return (lo - 3) / 6 + 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{};
	cin >> N;
	cout << solve(N) << "\n";
	return 0;
}
