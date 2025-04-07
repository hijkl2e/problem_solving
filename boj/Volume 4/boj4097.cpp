#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N, N) {
		ll sum{}, minv{}, ans = -INF;
		while (N--) {
			int x{};
			cin >> x;
			sum += x;
			ans = max(ans, sum - minv);
			minv = min(minv, sum);
		}
		cout << ans << "\n";
	}
	return 0;
}
