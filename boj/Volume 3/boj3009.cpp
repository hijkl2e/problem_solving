#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{};
	for (int i = 0; i < 3; ++i) {
		int x{}, y{};
		cin >> x >> y;
		a ^= x;
		b ^= y;
	}
	cout << a << " " << b << "\n";
	return 0;
}
