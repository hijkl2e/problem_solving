#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans{};
	while (N--) {
		int x{}, y{};
		cin >> x >> y;
		ans += y % x;
	}
	cout << ans << "\n";
	return 0;
}
