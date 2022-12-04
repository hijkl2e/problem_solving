#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{};
	cin >> x;
	x = min(9, x / 10);
	x = x < 6 ? 4 : x;
	char c = 'A' + 9 - x;
	cout << c << "\n";
	return 0;
}
