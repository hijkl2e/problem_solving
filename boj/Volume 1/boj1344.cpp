#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll fact(int n) {
	ll ret = 1;
	for (int i = 1; i <= n; ++i) {
		ret *= i;
	}
	return ret;
}

ll nCr(int n, int r) {
	return fact(n) / (fact(r) * fact(n - r));
}

double solve(double p) {
	double ret = 1;
	for (int x : {2, 3, 5, 7, 11, 13, 17}) {
		ret -= nCr(18, x) * pow(p, x) * pow(1 - p, 18 - x);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	double p1{}, p2{};
	cin >> p1 >> p2;
	p1 /= 100, p2 /= 100;
	double ans = 1 - solve(p1) * solve(p2);
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
