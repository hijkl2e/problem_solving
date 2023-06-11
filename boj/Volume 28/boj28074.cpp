#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	string mobis = "MOBIS";
	bool yes = true;
	for (char c : mobis) {
		if (S.find(c) == -1) {
			yes = false;
			break;
		}
	}
	cout << (yes ? "YES" : "NO") << "\n";
	return 0;
}
