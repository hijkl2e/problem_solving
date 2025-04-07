#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, L{}, W{}, H{};
	cin >> N >> L >> W >> H;
	double lo = 1e-3;
	double hi = 1e9;
	for (int i = 0; i < 100; ++i) {
		double mid = (lo + hi) / 2;
		__int128 l = L / mid;
		__int128 w = W / mid;
		__int128 h = H / mid;
		if (l * w * h < N) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	cout << fixed << setprecision(10);
	cout << hi << "\n";
	return 0;
}
