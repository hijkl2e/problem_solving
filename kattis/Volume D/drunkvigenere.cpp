#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	for (int i = 0; i < s1.size(); ++i) {
		if (i % 2) {
			s1[i] = (s1[i] + s2[i] - 2 * 'A') % 26 + 'A';
		} else {
			s1[i] = (s1[i] - s2[i] + 26) % 26 + 'A';
		}
	}
	cout << s1 << "\n";
	return 0;
}
