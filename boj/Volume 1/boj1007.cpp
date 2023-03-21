#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> x(N);
		vector<int> y(N);
		for (int i = 0; i < N; ++i) {
			cin >> x[i] >> y[i];
		}
		double ans = INF;
		for (int i = 0; i < (1 << N); ++i) {
			if (__builtin_popcount(i) != N / 2) {
				continue;
			}
			ll x_sum{}, y_sum{};
			for (int j = 0; j < N; ++j) {
				if (i & (1 << j)) {
					x_sum += x[j];
					y_sum += y[j];
				} else {
					x_sum -= x[j];
					y_sum -= y[j];
				}
			}
			ans = min(ans, sqrt(x_sum * x_sum + y_sum * y_sum));
		}
		cout << fixed << setprecision(10);
		cout << ans << "\n";
	}
	return 0;
}
