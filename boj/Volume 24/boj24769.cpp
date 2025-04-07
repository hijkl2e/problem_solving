#include <bits/stdc++.h>

using namespace std;

using si = pair<string, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	set<char> vowel{'a', 'e', 'i', 'o', 'u', 'y'};
	int N{};
	while (cin >> N, N) {
		cin.ignore();
		si ans{"", -1};
		while (N--) {
			string s;
			getline(cin, s);
			int cnt{};
			for (int i = 0; i < s.size() - 1; ++i) {
				if (s[i] == s[i + 1] && vowel.count(s[i])) {
					++cnt;
				}
			}
			if (ans.second < cnt) {
				ans = {s, cnt};
			}
		}
		cout << ans.first << "\n";
	}
	return 0;
}
