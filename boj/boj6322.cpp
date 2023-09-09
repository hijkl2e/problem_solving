#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{};
	for (int tc = 1; cin >> a >> b >> c, a; ++tc) {
		if (tc > 1) {
			cout << "\n";
		}
		cout << "Triangle #" << tc << "\n";
		double ans{};
		if (a == -1 || b == -1) {
			if (a >= c || b >= c) {
				cout << "Impossible.\n";
				continue;
			}
			cout << (a == -1 ? "a" : "b") << " = ";
			if (b == -1) {
				swap(a, b);
			}
			ans = sqrt(c * c - b * b);
		} else {
			cout << "c = ";
			ans = sqrt(a * a + b * b);
		}
		cout << fixed << setprecision(3);
		cout << ans << "\n";
	}
	return 0;
}
