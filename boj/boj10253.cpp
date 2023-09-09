#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int a{}, b{};
		cin >> a >> b;
		while (a > 1) {
			int x = (b - 1) / a + 1;
			tie(a, b) = make_pair(a * x - b, b * x);
			int g = gcd(a, b);
			a /= g, b /= g;
		}
		cout << b << "\n";
	}
	return 0;
}
