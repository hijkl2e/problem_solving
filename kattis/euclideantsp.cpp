#include <bits/stdc++.h>

using namespace std;

int n;
double p, s, v;

double f(double c) {
	return n * pow(log2(n), c * sqrt(2)) / (p * 1e9) + s * (1 + 1 / c) / v;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> p >> s >> v;
	double lo = 0, hi = 100;
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
	cout << f(hi) << " " << hi << "\n";
	return 0;
}
