#include <bits/stdc++.h>

using namespace std;

double solve(int p, int a, int b, int c, int d, int k) {
	return p * (sin(a * k + b) + cos(c * k + d) + 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int p{}, a{}, b{}, c{}, d{}, N{};
	cin >> p >> a >> b >> c >> d >> N;
	double maxv = -1e9;
	double ans{};
	for (int k = 1; k <= N; ++k) {
		double price = solve(p, a, b, c, d, k);
		maxv = max(maxv, price);
		ans = max(ans, maxv - price);
	}
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
