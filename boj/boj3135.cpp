#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{};
	cin >> a >> b;
	int ans = abs(a - b);
	int N{};
	cin >> N;
	while (N--) {
		int x{};
		cin >> x;
		ans = min(ans, abs(x - b) + 1);
	}
	cout << ans << "\n";
	return 0;
}
