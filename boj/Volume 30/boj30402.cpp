#include <bits/stdc++.h>

using namespace std;

int solve() {
	char c;
	while (cin >> c) {
		if (c == 'w' || c == 'b' || c == 'g') {
			return c == 'w' ? 0 : c == 'b' ? 1 : 2;
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x = solve();
	string ans = x == 0 ? "chunbae" : x == 1 ? "nabi" : "yeongcheol";
	cout << ans << "\n";
	return 0;
}
