#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	getline(cin, s);
	map<char, int> s2i{
		{'P', 0}, {'K', 1}, {'H', 2}, {'T', 3}
	};
	vector<int> A(4, 13);
	set<string> S;
	bool yes = true;
	for (int i = 0; i < s.size(); i += 3) {
		yes &= S.insert(s.substr(i, 3)).second;
		--A[s2i[s[i]]];
	}
	if (yes) {
		for (int i = 0; i < 4; ++i) {
			cout << A[i] << (i == 3 ? "\n" : " ");
		}
	} else {
		cout << "GRESKA\n";
	}
	return 0;
}
