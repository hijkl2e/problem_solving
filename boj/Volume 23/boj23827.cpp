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
	ll sum = accumulate(A.begin(), A.end(), 0LL);
	ll ans{};
	for (int i = 0; i < N; ++i) {
		ans = (ans + A[i] * (sum - A[i])) % MOD;
	}
	ans = 500000004 * ans % MOD;
	cout << ans << "\n";
	return 0;
}
