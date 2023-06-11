#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{};
	cin >> a >> b >> c;
	int ans = (a + 1) * (b + 1) / (c + 1) - 1;
	cout << ans << "\n";
	return 0;
}
