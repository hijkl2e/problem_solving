#include <bits/stdc++.h>

using namespace std;

bool solve(string &s) {
	for (int i = 1; i < s.size(); ++i) {
		set<string> S;
		string t(2, '*');
		for (int j = 0; j + i < s.size(); ++j) {
			t[0] = s[j];
			t[1] = s[j + i];
			if (!S.insert(t).second) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	while (getline(cin, S), S != "*") {
		cout << S << " is " << (solve(S) ? "" : "NOT ") << "surprising.\n";
	}
	return 0;
}
