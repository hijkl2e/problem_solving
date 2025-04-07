#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	for (auto &c : S) {
		if (isupper(c)) {
			c = (c - 'A' + 13) % 26 + 'A';
		} else if (islower(c)) {
			c = (c - 'a' + 13) % 26 + 'a';
		}
	}
	cout << S << "\n";
	return 0;
}
