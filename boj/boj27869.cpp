#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Q{};
	cin >> N >> Q;
	vector<ll> E(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> E[i];
	}
	vector<ll> psum(N + 1);
	partial_sum(E.begin(), E.end(), psum.begin());
	set<int> S;
	while (Q--) {
		int q{}, a{}, b{};
		cin >> q >> a;
		if (q == 1) {
			S.insert(a);
			continue;
		}
		cin >> b;
		auto it = S.lower_bound(b);
		if (it != S.begin()) {
			a = max(a, *--it + 1);
		}
		ll ans = psum[b] - psum[a - 1];
		cout << ans << "\n";
	}
	return 0;
}
