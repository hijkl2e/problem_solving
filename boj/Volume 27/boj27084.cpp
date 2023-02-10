#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 0; i < N; ++i) {
		int x{};
		cin >> x;
		++A[x];
	}
	ll ans = 1;
	for (int i = 1; i <= N; ++i) {
		ans = ans * (A[i] + 1) % MOD;
	}
	ans = (ans + MOD - 1) % MOD;
	cout << ans << "\n";
	return 0;
}
