#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	ll x = 1;
	bool large{}, error{};
	for (int i = 0; i < N; ++i) {
		if (large) {
			x = (2 * x - (B[i] % MOD) + MOD) % MOD;
		} else {
			x = 2 * x - B[i];
			if (x < 0) {
				error = true;
				break;
			} else if (x >= (1LL << 60)) {
				large = true;
				x %= MOD;
			}
		}
	}
	x %= MOD;
	if (error) {
		cout << "error\n";
	} else {
		cout << x << "\n";
	}
	return 0;
}
