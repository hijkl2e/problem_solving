#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	string s1 = S.substr(0, S.size() / 2);
	string s2 = S.substr(S.size() / 2);
	int rv = accumulate(s1.begin(), s1.end(), 0) - 'A' * s1.size();
	for (auto &c : s1) {
		c = (c - 'A' + rv) % 26 + 'A';
	}
	rv = accumulate(s2.begin(), s2.end(), 0) - 'A' * s2.size();
	for (auto &c : s2) {
		c = (c - 'A' + rv) % 26 + 'A';
	}
	for (int i = 0; i < s1.size(); ++i) {
		s1[i] = (s1[i] + s2[i] - 2 * 'A') % 26 + 'A';
	}
	cout << s1 << "\n";
	return 0;
}
