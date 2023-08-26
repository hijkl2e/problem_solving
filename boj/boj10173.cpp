#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	while (getline(cin, S), S != "EOI") {
		for (auto &c : S) {
			if (isupper(c)) {
				c = tolower(c);
			}
		}
		cout << (S.find("nemo") == -1 ? "Missing" : "Found") << "\n";
	}
	return 0;
}
