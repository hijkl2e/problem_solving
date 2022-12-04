#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<string, int> A;
	string s;
	while (cin >> s) {
		if (s == "define") {
			int i{};
			string x;
			cin >> i >> x;
			A[x] = i;
			continue;
		}
		string x, z;
		char y{};
		cin >> x >> y >> z;
		auto it1 = A.find(x);
		auto it2 = A.find(z);
		if (it1 == A.end() || it2 == A.end()) {
			cout << "undefined\n";
		} else {
			bool yes{};
			yes |= it1->second < it2->second && y == '<';
			yes |= it1->second > it2->second && y == '>';
			yes |= it1->second == it2->second && y == '=';
			cout << (yes ? "true" : "false") << "\n";
		}
	}
	return 0;
}
