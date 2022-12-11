#include <bits/stdc++.h>

using namespace std;

using dd = pair<double, double>;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<dd> A(N + 1);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first >> A[i].second;
	}
	A[N].first = 4e18;
	cin >> A[N].second;
	int M{};
	cin >> M;
	while (M--) {
		double e{}, m{};
		cin >> e >> m;
		vector<dd> B(A.begin(), A.end());
		for (auto &p : B) {
			double minv = min(e, p.first);
			e -= minv;
			p.first -= minv;
		}
		double lo = 0, hi = 1e12;
		for (int i = 0; i < 100; ++i) {
			double mid = (lo + hi) / 2;
			double x = mid;
			double res{};
			for (auto &p : B) {
				double minv = min(x, p.first);
				x -= minv;
				res += minv * (1 - p.second / 100);
			}
			if (res < m) {
				lo = mid;
			} else {
				hi = mid;
			}
		}
		cout << fixed << setprecision(10);
		cout << hi << "\n";
	}
	return 0;
}
