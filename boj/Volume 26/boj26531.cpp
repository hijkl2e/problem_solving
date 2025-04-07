#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{}, y{}, z{};
	char c{};
	cin >> x >> c >> y >> c >> z;
	cout << (x + y == z ? "YES" : "NO") << "\n";
	return 0;
}
