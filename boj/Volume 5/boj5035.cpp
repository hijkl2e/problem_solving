#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	double L{}, K{}, T1{}, T2{}, H{};
	cin >> L >> K >> T1 >> T2 >> H;
	double lo = 0, hi = 1e9;
	for (int i = 0; i < 100; ++i) {
		double mid = (lo + hi) / 2;
		if (mid * T1 + K * L / mid < H + (T1 + T2) * K) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	double X = hi * T1;
	cout << fixed << setprecision(10);
	cout << (L < H ? X : H) << " " << (L > H ? H : X) << "\n";
	return 0;
}
