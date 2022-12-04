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
		deque<bool> chk(26);
		for (char c : S) {
			if (isalpha(c)) {
				chk[tolower(c) - 'a'] = true;
			}
		}
		vector<char> A;
		for (int i = 0; i < 26; ++i) {
			if (!chk[i]) {
				A.push_back('a' + i);
			}
		}
		if (A.empty()) {
			cout << "pangram\n";
		} else {
			cout << "missing ";
			for (char c : A) {
				cout << c;
			}
			cout << "\n";
		}
	}
	return 0;
}
