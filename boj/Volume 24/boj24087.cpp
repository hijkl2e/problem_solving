#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int s{}, a{}, b{};
	cin >> s >> a >> b;
	int ans = 250;
	s -= a;
	if (s > 0) {
		ans += ((s - 1) / b + 1) * 100;
	}
	cout << ans << "\n";
	return 0;
}
