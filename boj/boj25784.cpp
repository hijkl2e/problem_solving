#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{};
	cin >> a >> b >> c;
	int ans = 3;
	if (a + b == c || b + c == a || c + a == b) {
		ans = 1;
	} else if (a * b == c || b * c == a || c * a == b) {
		ans = 2;
	}
	cout << ans << "\n";
	return 0;
}
