#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<__int128, __int128>;

ii solve(ll N, ll mod) {
	if (N == 1) {
		return {1, 0};
	}
	auto [x, y] = solve(N / 2, mod);
	ii ret{x * (x + 2 * y) % mod, (x * x + y * y) % mod};
	if (N % 2) {
		ret = {(ret.first + ret.second) % mod, ret.first};
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{};
	cin >> N;
	vector<ll> A(149);
	for (int i = 0; i < A.size(); ++i) {
		A[i] = i + 1;
	}
	for (ll i = 0, j = 1000; i < 11; ++i, j *= 10) {
		vector<ll> B;
		for (int k = 0; k < 10; ++k) {
			for (ll x : A) {
				ll y = j / 20 * 3 * k + x;
				if (solve(y, j).first == N % j) {
					B.push_back(y);
				}
			}
		}
		A = B;
	}
	cout << (A.size() ? A[0] : -1) << "\n";
	return 0;
}
