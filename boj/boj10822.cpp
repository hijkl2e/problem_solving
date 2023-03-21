#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{}, ans{};
	char c{};
	while (cin >> x) {
		ans += x;
		cin >> c;
	}
	cout << ans << "\n";
	return 0;
}
