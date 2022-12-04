#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	set<char> vowel{'a', 'e', 'i', 'o', 'u'};
	string S;
	getline(cin, S);
	for (int i = 0; i < S.size(); ++i) {
		cout << S[i];
		if (vowel.count(S[i])) {
			i += 2;
		}
	}
	cout << "\n";
	return 0;
}
