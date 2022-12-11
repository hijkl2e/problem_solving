#include <bits/stdc++.h>

using namespace std;

int N;
vector<double> x, y;

double f(double z) {
	double ret{};
	for (int i = 0; i < N; ++i) {
		ret = max(ret, (x[i] - z) * (x[i] - z) + y[i] * y[i]);
	}
	return sqrt(ret);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while (cin >> N, N) {
		x.resize(N);
		y.resize(N);
		for (int i = 0; i < N; ++i) {
			cin >> x[i] >> y[i];
		}
		double lo = -3e5, hi = 3e5;
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
		cout << fixed << setprecision(10);
		cout << lo << " " << f(lo) << "\n";
	}
	return 0;
}
