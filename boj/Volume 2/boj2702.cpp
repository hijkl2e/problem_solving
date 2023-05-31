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
		cout << lcm(a, b) << " " << gcd(a, b) << "\n";
	}
	return 0;
}
