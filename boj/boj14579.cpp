#include <bits/stdc++.h>

using namespace std;

const int MOD = 14579;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{};
	cin >> a >> b;
	int ans = 1;
	int x = a * (a - 1) / 2;
	for (int i = a; i <= b; ++i) {
		x = (x + i) % MOD;
		ans = ans * x % MOD;
	}
	cout << ans << "\n";
	return 0;
}
