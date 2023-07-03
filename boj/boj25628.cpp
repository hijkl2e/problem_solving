#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{};
	cin >> a >> b;
	int ans = min(a / 2, b);
	cout << ans << "\n";
	return 0;
}
