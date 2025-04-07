#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{};
	cin >> x;
	int ans{};
	while (x >= 10) {
		string s = to_string(x);
		x = 1;
		for (char c : s) {
			x *= c - '0';
		}
		++ans;
	}
	cout << ans << "\n";
	return 0;
}
