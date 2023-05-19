#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	s1 += s2;
	sort(s1.begin(), s1.end());
	cout << s1 << "\n";
	return 0;
}
