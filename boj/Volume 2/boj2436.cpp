#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int g{}, l{};
	cin >> g >> l;
	int x = l / g;
	int ans_x{}, ans_y{};
	for (int i = 1; i * i <= x; ++i) {
		if (x % i == 0 && gcd(i, x / i) == 1) {
			ans_x = i * g;
			ans_y = x / i * g;
		}
	}
	cout << ans_x << " " << ans_y << "\n";
	return 0;
}
