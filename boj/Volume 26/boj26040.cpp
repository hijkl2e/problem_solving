#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	deque<bool> A(26);
	char c{};
	while (cin >> c) {
		A[c - 'A'] = true;
	}
	for (auto &c : S) {
		if (isupper(c) && A[c - 'A']) {
			c = tolower(c);
		}
	}
	cout << S << "\n";
	return 0;
}
