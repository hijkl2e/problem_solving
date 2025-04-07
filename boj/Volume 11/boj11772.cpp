#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int sum{};
	while (N--) {
		int x{};
		cin >> x;
		int p = x % 10;
		x /= 10;
		int y = 1;
		while (p--) {
			y *= x;
		}
		sum += y;
	}
	cout << sum << "\n";
	return 0;
}
