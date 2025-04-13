#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, a{}, b{};
	cin >> N >> a >> b;
	int x{}, y{};
	x = y = 1;
	while (N--) {
		x += a;
		y += b;
		if (x < y) {
			swap(x, y);
		} else if (x == y) {
			--y;
		}
	}
	cout << x << " " << y << "\n";
	return 0;
}
