#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int a{}, b{}, c{};
		cin >> a >> b >> c;
		cout << min({a, b, c}) << "\n";
	}
	return 0;
}
