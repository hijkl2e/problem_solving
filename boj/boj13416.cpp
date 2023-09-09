#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		int ans{};
		while (N--) {
			int a{}, b{}, c{};
			cin >> a >> b >> c;
			ans += max({a, b, c, 0});
		}
		cout << ans << "\n";
	}
	return 0;
}
