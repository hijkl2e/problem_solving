#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, x{}, b{}, y{}, T{};
	cin >> a >> x >> b >> y >> T;
	int ans_x = a + 21 * max(T - 30, 0) * x;
	int ans_y = b + 21 * max(T - 45, 0) * y;
	cout << ans_x << " " << ans_y << "\n";
	return 0;
}
