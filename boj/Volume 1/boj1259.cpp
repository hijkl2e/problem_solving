#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	while (getline(cin, s), s != "0") {
		string t = s;
		reverse(t.begin(), t.end());
		cout << (s == t ? "yes" : "no") << "\n";
	}
	return 0;
}
