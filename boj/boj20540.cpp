#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string istj = "ISTJ";
	string enfp = "ENFP";
	string S;
	getline(cin, S);
	for (int i = 0; i < 4; ++i) {
		S[i] = S[i] == istj[i] ? enfp[i] : istj[i];
	}
	cout << S << "\n";
	return 0;
}
