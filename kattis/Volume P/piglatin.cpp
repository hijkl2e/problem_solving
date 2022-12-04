#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	set<char> vowel{'a', 'e', 'i', 'o', 'u', 'y'};
	string S;
	while (getline(cin, S)) {
		istringstream iss(S);
		for (int i = 0; iss >> S; ++i) {
			if (i) {
				cout << " ";
			}
			for (int j = 0; j < S.size(); ++j) {
				if (vowel.count(S[j])) {
					if (j) {
						cout << S.substr(j) << S.substr(0, j) << "ay";
					} else {
						cout << S << "yay";
					}
					break;
				}
			}
		}
		cout << "\n";
	}
	return 0;
}
