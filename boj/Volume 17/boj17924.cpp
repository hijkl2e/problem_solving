#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int x{}, y{};
	cin >> x >> y;
	while (--N) {
		int a{}, b{};
		cin >> a >> b;
		x = max(x, a);
		y = min(y, b);
	}
	if (x <= y) {
		cout << "gunilla has a point\n";
	} else {
		cout << "edward is right\n";
	}
	return 0;
}
