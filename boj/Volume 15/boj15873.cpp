#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	int ans{};
	if (s.size() == 2) {
		ans = s[0] + s[1] - 2 * '0';
	} else if (s.size() == 3) {
		ans = 10 + (s.back() == '0' ? s.front() : s.back()) - '0';
	} else {
		ans = 20;
	}
	cout << ans << "\n";
	return 0;
}
