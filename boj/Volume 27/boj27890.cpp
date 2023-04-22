#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{}, N{};
	cin >> x >> N;
	while (N--) {
		if (x % 2) {
			x = (2 * x) ^ 6;
		} else {
			x = (x / 2) ^ 6;
		}
	}
	cout << x << "\n";
	return 0;
}
