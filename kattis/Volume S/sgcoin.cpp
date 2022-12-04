#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll v{};
	cin >> v;
	v = (v * 31 + 97) * 7 % MOD;
	cout << "a " << (2 * MOD - 7 - v) % MOD << "\n";
	cout << "b 826\n";
	return 0;
}
