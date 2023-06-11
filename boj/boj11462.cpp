#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	while (getline(cin, s), s != "END") {
		for (int i = s.size() - 1; i >= 0; --i) {
			if (s[i] != '0') {
				--s[i];
				break;
			}
		}
		cout << stoi(s) << "\n";
	}
	return 0;
}
