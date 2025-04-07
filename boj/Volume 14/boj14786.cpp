#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int A{}, B{}, C{};
	cin >> A >> B >> C;
	double lo = 0, hi = 1e6;
	for (int i = 0; i < 100; ++i) {
		double mid = (lo + hi) / 2;
		if (A * mid + B * sin(mid) > C) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	cout << fixed << setprecision(10);
	cout << lo << "\n";
	return 0;
}
