#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S, T;
	getline(cin, S);
	getline(cin, T);
	for (int i = 0; i < S.size(); ++i) {
		if (S[i] == ' ') {
			continue;
		}
		S[i] = (S[i] - T[i % T.size()] + 25) % 26 + 'a';
	}
	cout << S << "\n";
	return 0;
}
