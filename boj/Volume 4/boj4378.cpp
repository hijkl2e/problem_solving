#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string key = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	string S;
	while (getline(cin, S)) {
		for (auto &c : S) {
			if (key.find(c) == -1) {
				continue;
			}
			c = key[key.find(c) - 1];
		}
		cout << S << "\n";
	}
	return 0;
}
