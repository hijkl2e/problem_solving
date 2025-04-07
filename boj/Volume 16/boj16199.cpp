#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int y1{}, m1{}, d1{}, y2{}, m2{}, d2{};
	cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
	int x = (y2 - y1) + ((m1 == m2 && d1 <= d2) || m1 < m2) - 1;
	int y = y2 - y1 + 1;
	int z = y2 - y1;
	cout << x << "\n" << y << "\n" << z << "\n";
	return 0;
}
