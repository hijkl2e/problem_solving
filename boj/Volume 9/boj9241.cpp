#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	while (s1.size() && s2.size() && s1.back() == s2.back()) {
		s1.pop_back();
		s2.pop_back();
	}
	int p{};
	while (p < s1.size() && p < s2.size() && s1[p] == s2[p]) {
		++p;
	}
	int ans = s2.size() - p;
	cout << ans << "\n";
	return 0;
}
