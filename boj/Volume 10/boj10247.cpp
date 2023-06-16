#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> x, v;

double f(double t) {
	double minv = 4e18, maxv = -4e18;
	for (int i = 0; i < N; ++i) {
		double y = x[i] + t * v[i];
		minv = min(minv, y);
		maxv = max(maxv, y);
	}
	return maxv - minv;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while (cin >> N, N) {
		x.resize(N);
		v.resize(N);
		for (int i = 0; i < N; ++i) {
			cin >> x[i] >> v[i];
		}
		double lo = 0, hi = 1e7;
		for (int i = 0; i < 100; ++i) {
			double d = (hi - lo) / 3;
			double m1 = lo + d;
			double m2 = hi - d;
			if (f(m1) > f(m2)) {
				lo = m1;
			} else {
				hi = m2;
			}
		}
		cout << fixed << setprecision(2);
		cout << f(lo) << "\n";
	}
	return 0;
}
