#include <bits/stdc++.h>

using namespace std;

bool solve(string s1, string s2) {
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	return s1 == s2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		string s1, s2;
		cin >> s1 >> s2;
		cout << s1 << " & " << s2 << " are " << (solve(s1, s2) ? "" : "NOT ") << "anagrams.\n";
	}
	return 0;
}
