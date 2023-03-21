#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int sum{}, ans{};
	for (int i = 0; i < 10; ++i) {
		int x{}, y{};
		cin >> x >> y;
		sum += y - x;
		ans = max(ans, sum);
	}
	cout << ans << "\n";
	return 0;
}
