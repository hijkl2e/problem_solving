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
		bool yes = true;
		for (int i = 3; i <= S.size(); i = 2 * i + 1) {
			for (int j = 0; j < i / 2; ++j) {
				if (S[j] == S[i - j - 1]) {
					yes = false;
					i = S.size();
					break;
				}
			}
		}
		cout << (yes ? "YES" : "NO") << "\n";
	}
	return 0;
}
