#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		string s1, s2;
		cin >> s1 >> s2;
		int x{}, y{};
		for (int i = 0; i < s1.size(); ++i) {
			if (s1[i] == s2[i]) {
				continue;
			} else if (s1[i] == '1') {
				++x;
			} else {
				++y;
			}
		}
		int ans = max(x, y);
		cout << ans << "\n";
	}
	return 0;
}
