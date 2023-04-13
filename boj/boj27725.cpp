#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> P(N);
	for (int i = 0; i < N; ++i) {
		cin >> P[i];
	}
	ll K{};
	cin >> K;
	ll ans{};
	for (int i = 0; i < N; ++i) {
		ll j = P[i];
		while (j <= K) {
			ans += K / j;
			j *= P[i];
		}
	}
	cout << ans << "\n";
	return 0;
}
