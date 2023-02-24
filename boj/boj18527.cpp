#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, T{};
	cin >> N >> T;
	vector<int> x(N);
	for (int i = 0; i < N; ++i) {
		cin >> x[i];
	}
	ll ans = 1;
	for (int i = N - 1, sum = 0; i >= 0; --i) {
		sum += x[i];
		ans = ans * (T - sum + (N - i) % N + 1) % MOD;
	}
	cout << ans << "\n";
	return 0;
}
