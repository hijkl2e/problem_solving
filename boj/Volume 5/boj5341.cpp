#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{};
	while (cin >> x, x) {
		cout << x * (x + 1) / 2 << "\n";
	}
	return 0;
}
