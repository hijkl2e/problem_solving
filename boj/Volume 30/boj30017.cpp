#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{};
	cin >> a >> b;
	int ans = 2 * min(a, b + 1) - 1;
	cout << ans << "\n";
	return 0;
}
