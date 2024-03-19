#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	while (getline(cin, S)) {
		for (auto &c : S) {
			if (c == 'E' || c == 'I' || c == 'e' || c == 'i') {
				c ^= 12;
			}
		}
		cout << S << "\n";
	}
	return 0;
}
