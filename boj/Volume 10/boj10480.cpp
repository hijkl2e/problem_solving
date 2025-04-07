#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int x{};
		cin >> x;
		cout << x << " is " << (x % 2 ? "odd" : "even") << "\n";
	}
	return 0;
}
