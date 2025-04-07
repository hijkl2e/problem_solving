#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, K{};
	cin >> N >> K;
	vector<ll> x(N);
	vector<ll> y(N);
	for (int i = 0; i < N; ++i) {
		cin >> x[i] >> y[i];
	}
	map<ll, ll> freq;
	for (int i = 0; i < N; ++i) {
		++freq[y[i] - K * x[i]];
	}
	ll ans{};
	for (auto &[u, v] : freq) {
		ans += v * (v - 1);
	}
	cout << ans << "\n";
	return 0;
}
