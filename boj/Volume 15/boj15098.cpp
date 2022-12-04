#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	set<string> S;
	bool yes = true;
	string s;
	while (cin >> s) {
		yes &= S.insert(s).second;
	}
	cout << (yes ? "yes" : "no") << "\n";
	return 0;
}
