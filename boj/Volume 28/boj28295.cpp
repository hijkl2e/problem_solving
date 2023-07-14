#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{};
	for (int i = 0; i < 10; ++i) {
		int y{};
		cin >> y;
		x = (x + y) % 4;
	}
	cout << "NESW"[x] << "\n";
	return 0;
}
