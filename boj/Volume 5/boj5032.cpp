#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int e{}, f{}, c{};
	cin >> e >> f >> c;
	e += f;
	int ans{};
	while (e >= c) {
		ans += e / c;
		e = e / c + e % c;
	}
	cout << ans << "\n";
	return 0;
}
