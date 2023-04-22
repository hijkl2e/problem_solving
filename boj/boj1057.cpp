#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, x{}, y{};
	cin >> N >> x >> y;
	int ans{};
	while (x != y) {
		x = (x + 1) / 2;
		y = (y + 1) / 2;
		++ans;
	}
	cout << ans << "\n";
	return 0;
}
