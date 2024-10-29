#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{};
	cin >> a >> b;
	int g = gcd(a, b);
	for (int i = 1; i <= g; ++i) {
		if (g % i == 0) {
			cout << i << " " << a / i << " " << b / i << "\n";
		}
	}
	return 0;
}
