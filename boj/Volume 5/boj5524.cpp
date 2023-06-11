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
		for (auto &c : S) {
			c = tolower(c);
		}
		cout << S << "\n";
	}
	return 0;
}
