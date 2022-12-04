#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		string S;
		getline(cin, S);
		list<char> li;
		auto it = li.begin();
		for (char c : S) {
			if (c == '<') {
				if (it != li.begin()) {
					it = li.erase(--it);
				}
			} else if (c == '[') {
				it = li.begin();
			} else if (c == ']') {
				it = li.end();
			} else {
				it = li.insert(it, c);
				++it;
			}
		}
		for (char c : li) {
			cout << c;
		}
		cout << "\n";
	}
	return 0;
}
