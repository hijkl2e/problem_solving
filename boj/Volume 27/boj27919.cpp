#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int x{}, y{};
	for (char c : S) {
		if (c == 'U' || c == 'C') {
			++x;
		} else {
			++y;
		}
	}
	string ans;
	if (x > (y + 1) / 2) {
		ans += "U";
	}
	if (y) {
		ans += "DP";
	}
	cout << ans << "\n";
	return 0;
}
