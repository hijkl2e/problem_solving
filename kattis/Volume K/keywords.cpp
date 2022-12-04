#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	set<string> S;
	while (N--) {
		string s;
		getline(cin, s);
		for (auto &c : s) {
			c = tolower(c);
			if (c == '-') {
				c = ' ';
			}
		}
		S.insert(s);
	}
	cout << S.size() << "\n";
	return 0;
}
