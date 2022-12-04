#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int l{}, r{};
	cin >> l >> r;
	if (l || r) {
		cout << (l == r ? "Even" : "Odd") << " " << 2 * max(l, r) << "\n";
	} else {
		cout << "Not a moose\n";
	}
	return 0;
}
