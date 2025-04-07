#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{};
	cin >> a >> b;
	int disc = lround(sqrt(a * a - b));
	int x1 = -(a + disc);
	int x2 = -(a - disc);
	cout << x1;
	if (x1 < x2) {
		cout << " " << x2;
	}
	cout << "\n";
	return 0;
}
