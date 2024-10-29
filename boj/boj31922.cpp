#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, p{}, c{};
	cin >> a >> p >> c;
	int ans = max(a + c, p);
	cout << ans << "\n";
	return 0;
}
