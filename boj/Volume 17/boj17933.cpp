#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	deque<bool> B(N);
	ll p = 1;
	for (int i = 0; i < N - 1; ++i) {
		if (A[i] > 1) {
			A[i + 1] += A[i] / 2;
			B[i + 1] = true;
		}
		A[i] %= 2;
		p = 2 * p % MOD;
	}
	ll ans{};
	for (int i = N - 1; i >= 0; --i) {
		if (A[i] % 2 && !B[i]) {
			ans = (ans + p) % MOD;
		}
		p = 500000004 * p % MOD;
	}
	cout << ans << "\n";
	return 0;
}
