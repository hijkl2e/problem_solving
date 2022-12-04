#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	set<string> S;
	string s;
	while (getline(cin, s)) {
		istringstream iss(s);
		for (int i = 0; iss >> s; ++i) {
			if (i) {
				cout << " ";
			}
			string lower = s;
			for (auto &c : lower) {
				c = tolower(c);
			}
			cout << (S.insert(lower).second ? s : ".");
		}
		cout << "\n";
	}
	return 0;
}
