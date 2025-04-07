#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	while (N--) {
		double d{}, f{}, p{};
		cin >> d >> f >> p;
		double ans = d * f * p + EPS;
		cout << fixed << setprecision(2);
		cout << "$" << ans << "\n";
	}
	return 0;
}
