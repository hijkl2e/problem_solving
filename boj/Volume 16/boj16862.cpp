#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<string, char> dict{
		{"at", '@'}, {"and", '&'}, {"one", '1'}, {"won", '1'}, {"to", '2'},
		{"too", '2'}, {"two", '2'}, {"for", '4'}, {"four", '4'}, {"bea", 'b'},
		{"be", 'b'}, {"bee", 'b'}, {"sea", 'c'}, {"see", 'c'}, {"eye", 'i'},
		{"oh", 'o'}, {"owe", 'o'}, {"are", 'r'}, {"you", 'u'}, {"why", 'y'}
	};
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		string S, L;
		getline(cin, S);
		L = S;
		for (auto &c : L) {
			c = tolower(c);
		}
		for (int i = 0, j = 4; i < S.size(); i += j) {
			char c = S[i];
			for (j = 4; j > 1; --j) {
				auto it = dict.find(L.substr(i, j));
				if (it == dict.end()) {
					continue;
				}
				c = it->second;
				if (isupper(S[i])) {
					c = toupper(c);
				}
				break;
			}
			cout << c;
		}
		cout << "\n";
	}
	return 0;
}
