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
		b = (b - 1) % 4;
		int x = a % 10;
		while (b--) {
			x = x * a % 10;
		}
		cout << (x ? x : 10) << "\n";
	}
	return 0;
}
