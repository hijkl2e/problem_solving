#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<string, string> dict;
	string s;
	while (getline(cin, s), s.size()) {
		istringstream iss(s);
		string s1, s2;
		iss >> s1 >> s2;
		dict[s2] = s1;
	}
	while (getline(cin, s)) {
		auto it = dict.find(s);
		if (it == dict.end()) {
			cout << "eh\n";
		} else {
			cout << it->second << "\n";
		}
	}
	return 0;
}
