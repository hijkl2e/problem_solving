#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	ll m{}, a{}, c{};
	vector<ll> x(N + 1);
	cin >> m >> a >> c >> x[0];
	for (int i = 1; i <= N; ++i) {
		x[i] = (a * x[i - 1] + c) % m;
	}
	int ans{};
	for (int i = 1; i <= N; ++i) {
		int lo = 1, hi = N + 1;
		bool yes{};
		while (lo < hi) {
			int mid = (lo + hi - 1) / 2;
			if (x[i] < x[mid]) {
				hi = mid;
			} else if (x[i] > x[mid]) {
				lo = mid + 1;
			} else {
				yes = true;
				break;
			}
		}
		if (yes) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
