#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	bool yes{};
	for (int i = 1; i < S.size(); ++i) {
		int x{}, y{};
		x = y = 1;
		for (int j = 0; j < S.size(); ++j) {
			if (j < i) {
				x *= S[j] - '0';
			} else {
				y *= S[j] - '0';
			}
		}
		if (x == y) {
			yes = true;
			break;
		}
	}
	cout << (yes ? "YES" : "NO") << "\n";
	return 0;
}
