#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	double ans{};
	while (N--) {
		double q{}, y{};
		cin >> q >> y;
		ans += q * y;
	}
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
