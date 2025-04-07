#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	bool yes = true;
	for (int i = 2; i < S.size(); ++i) {
		if (S[i] - S[i - 1] != S[1] - S[0]) {
			yes = false;
			break;
		}
	}
	cout << (yes ? "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!" : "흥칫뿡!! <(￣ ﹌ ￣)>") << "\n";
	return 0;
}
