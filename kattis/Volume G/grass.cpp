#include <bits/stdc++.h>

using namespace std;

using dd = pair<double, double>;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, l{}, w{};
	while (cin >> N >> l >> w) {
		vector<dd> A(N + 1);
		for (int i = 0; i < N; ++i) {
			int x{}, r{};
			cin >> x >> r;
			double y = sqrt(max(r * r - w * w / 4.0, 0.0));
			A[i] = {x - y, x + y};
		}
		A[N] = {l, l};
		sort(A.begin(), A.end());
		int ans{};
		double x{};
		for (int i = 0; i < N && x + EPS < l;) {
			double maxv{};
			while (i < N && A[i].first < x + EPS) {
				maxv = max(maxv, A[i++].second);
			}
			x = maxv;
			if (x + EPS < A[i].first) {
				ans = -1;
				break;
			}
			++ans;
		}
		cout << ans << "\n";
	}
	return 0;
}
