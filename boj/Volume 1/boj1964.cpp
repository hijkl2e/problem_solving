#include <bits/stdc++.h>

using namespace std;

const int MOD = 45678;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	N %= MOD;
	int ans = (N * (N + 1) / 2 % MOD * 3 + (N + 1)) % MOD;
	cout << ans << "\n";
	return 0;
}
