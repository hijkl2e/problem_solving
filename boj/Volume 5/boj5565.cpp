#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{};
	cin >> x;
	for (int i = 0; i < 9; ++i) {
		int y{};
		cin >> y;
		x -= y;
	}
	cout << x << "\n";
	return 0;
}
