#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	string ans;
	for (int i = 0; i < s2.size(); i += 3) {
		int x = stoi(s2.substr(i, 3)) - 1;
		ans += s1[x];
	}
	cout << ans << "\n";
	return 0;
}
