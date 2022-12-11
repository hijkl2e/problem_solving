#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	double N{};
	cin >> N;
	double lo = 1, hi = 11;
	for (int i = 0; i < 100; ++i) {
		double mid = (lo + hi) / 2;
		if (pow(mid, mid) < N) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	cout << fixed << setprecision(10);
	cout << lo << "\n";
	return 0;
}
