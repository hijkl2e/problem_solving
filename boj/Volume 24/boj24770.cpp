#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	while (cin >> N >> M, N) {
		ii ans{1, INF};
		while (N--) {
			int a{}, b{};
			cin >> a >> b;
			if (a > M) {
				continue;
			}
			double r1 = ans.second * 1.0 / ans.first;
			double r2 = b * 1.0 / a;
			if (r1 > r2 || (r1 == r2 && ans.first < a)) {
				ans = {a, b};
			}
		}
		if (ans.second == INF) {
			cout << "No suitable tickets offered\n";
		} else {
			cout << "Buy " << ans.first << " tickets for $" << ans.second << "\n";
		}
	}
	return 0;
}
