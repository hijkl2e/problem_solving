#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{}, d{}, N{};
	cin >> a >> b >> c >> d >> N;
	int ans = max(4 * N - a - b - c - d, 0);
	cout << ans << "\n";
	return 0;
}
