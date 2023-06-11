#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 3;
	while (T--) {
		string s;
		getline(cin, s);
		int cnt = 1, ans{};
		for (int i = 1; i < 8; ++i) {
			if (s[i] == s[i - 1]) {
				++cnt;
			} else {
				ans = max(ans, cnt);
				cnt = 1;
			}
		}
		ans = max(ans, cnt);
		cout << ans << "\n";
	}
	return 0;
}
