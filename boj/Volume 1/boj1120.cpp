#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s1, s2;
	cin >> s1 >> s2;
	int ans = s1.size();
	for (int i = 0; i + s1.size() <= s2.size(); ++i) {
		int cnt{};
		for (int j = 0; j < s1.size(); ++j) {
			if (s1[j] != s2[i + j]) {
				++cnt;
			}
		}
		ans = min(ans, cnt);
	}
	cout << ans << "\n";
	return 0;
}
