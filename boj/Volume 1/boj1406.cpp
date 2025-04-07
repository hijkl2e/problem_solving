#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	list<char> A;
	for (char c : S) {
		A.push_back(c);
	}
	auto it = A.end();
	int M{};
	cin >> M;
	while (M--) {
		char c{};
		cin >> c;
		if (c == 'L') {
			if (it != A.begin()) {
				--it;
			}
		} else if (c == 'D') {
			if (it != A.end()) {
				++it;
			}
		} else if (c == 'B') {
			if (it != A.begin()) {
				it = A.erase(--it);
			}
		} else {
			cin >> c;
			it = ++A.insert(it, c);
		}
	}
	for (char c : A) {
		cout << c;
	}
	cout << "\n";
	return 0;
}
