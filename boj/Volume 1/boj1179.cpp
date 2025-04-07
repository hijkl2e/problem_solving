#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll solve(ll N, ll K) {
	if (N == 1) {
		return 0;
	} else if (N / K > 1) {
		ll res = solve(N - N / K, K);
		return (res + max(res - N % K, 0LL) / (K - 1) + N - N % K) % N;
	} else {
		return (solve(N - 1, K) + K) % N;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, K{};
	cin >> N >> K;
	ll ans = K == 1 ? N : (solve(N, K) + 1);
	cout << ans << "\n";
	return 0;
}
