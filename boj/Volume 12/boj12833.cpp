#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{};
	cin >> a >> b >> c;
	int ans = c % 2 ? a ^ b : a;
	cout << ans << "\n";
	return 0;
}
