#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	for (int tc = 1; tc <= T; ++tc) {
		if (tc > 1) {
			cout << "\n";
		}
		string S;
		getline(cin, S);
		for (auto &c : S) {
			c = (c - 'A' + 1) % 26 + 'A';
		}
		cout << "String #" << tc << "\n";
		cout << S << "\n";
	}
	return 0;
}
