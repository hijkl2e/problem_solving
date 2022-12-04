#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, h{};
	cin >> a >> b >> h;
	int ans = max(h - b - 1, 0) / (a - b) + 1;
	cout << ans << "\n";
	return 0;
}
