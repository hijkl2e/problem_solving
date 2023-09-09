#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x1{}, y1{}, x2{}, y2{};
	cin >> x1 >> y1 >> x2 >> y2;
	int z1 = (y1 - 1) / x2 + 1;
	int z2 = (y2 - 1) / x1 + 1;
	cout << (z1 > z2 ? "PLAYER A" : z1 < z2 ? "PLAYER B" : "DRAW") << "\n";
	return 0;
}
