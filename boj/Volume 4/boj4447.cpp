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
		int g{}, b{};
		for (char c : S) {
			c = tolower(c);
			if (c == 'g') {
				++g;
			} else if (c == 'b') {
				++b;
			}
		}
		cout << S << " is " << (g > b ? "GOOD" : g < b ? "A BADDY" : "NEUTRAL") << "\n";
	}
	return 0;
}
