#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<ll> P(N);
	vector<ll> C(N);
	for (int i = 0; i < N; ++i) {
		cin >> P[i] >> C[i];
	}
	ll lo = 0, hi = 3e9;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		ll x{};
		for (int i = 0; i < N && x < M; ++i) {
			x += max(P[i] * mid - C[i], 0LL);
		}
		if (x < M) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	cout << hi << "\n";
	return 0;
}
