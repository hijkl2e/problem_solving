#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s1 = "KPNBRQ";
	string s2 = "013359";
	int ans{};
	for (int i = 0; i < 8; ++i) {
		string S;
		getline(cin, S);
		for (char c : S) {
			if (c == '.') {
				continue;
			}
			int x = isupper(c) ? 1 : -1;
			c = toupper(c);
			int p = s1.find(c);
			ans += x * (s2[p] - '0');
		}
	}
	cout << ans << "\n";
	return 0;
}
