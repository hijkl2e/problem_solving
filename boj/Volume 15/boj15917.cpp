#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int Q{};
	cin >> Q;
	while (Q--) {
		int x{};
		cin >> x;
		cout << ((x & -x) == x) << "\n";
	}
	return 0;
}
