#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		string S, T;
		getline(cin, S);
		getline(cin, T);
		for (auto &c : S) {
			if (c != ' ') {
				c = T[c - 'A'];
			}
		}
		cout << S << "\n";
	}
	return 0;
}
