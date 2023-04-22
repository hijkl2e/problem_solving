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
		list<char> A;
		auto it = A.begin();
		for (char c : S) {
			if (c == '-') {
				if (it != A.begin()) {
					it = A.erase(--it);
				}
			} else if (c == '<') {
				if (it != A.begin()) {
					--it;
				}
			} else if (c == '>') {
				if (it != A.end()) {
					++it;
				}
			} else {
				it = ++A.insert(it, c);
			}
		}
		for (char c : A) {
			cout << c;
		}
		cout << "\n";
	}
	return 0;
}
