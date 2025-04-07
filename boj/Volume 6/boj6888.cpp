#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{}, y{};
	cin >> x >> y;
	while (x <= y) {
		cout << "All positions change in year " << x << "\n";
		x += 60;
	}
	return 0;
}
