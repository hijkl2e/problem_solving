#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	list<char> li;
	auto it = li.begin();
	for (char c : S) {
		if (c == 'L') {
			--it;
		} else if (c == 'R') {
			++it;
		} else if (c == 'B') {
			it = li.erase(--it);
		} else {
			it = li.insert(it, c);
			++it;
		}
	}
	for (char c : li) {
		cout << c;
	}
	cout << "\n";
	return 0;
}
