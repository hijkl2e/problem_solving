#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int ans{}, x{};
	cin >> ans;
	char c{};
	bool flag{};
	while (cin >> c >> x) {
		flag |= c == '-';
		ans += (flag ? -1 : 1) * x;
	}
	cout << ans << "\n";
	return 0;
}
