#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9;

map<int, int> solve() {
	int N{};
	cin >> N;
	map<int, int> A;
	while (N--) {
		int x{};
		cin >> x;
		for (int i = 2; i * i <= x; ++i) {
			int cnt{};
			while (x % i == 0) {
				++cnt;
				x /= i;
			}
			if (cnt) {
				A[i] += cnt;
			}
		}
		if (x > 1) {
			++A[x];
		}
	}
	return A;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<int, int> A = solve();
	map<int, int> B = solve();
	ll ans = 1;
	bool flag{};
	for (auto &p : A) {
		int cnt = min(p.second, B[p.first]);
		while (cnt--) {
			ans *= p.first;
			if (ans >= MOD) {
				ans %= MOD;
				flag = true;
			}
		}
	}
	if (flag) {
		cout << setfill('0') << setw(9);
	}
	cout << ans << "\n";
	return 0;
}
