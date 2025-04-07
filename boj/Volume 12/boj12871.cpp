#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S, T;
	getline(cin, S);
	getline(cin, T);
	bool yes = true;
	for (int i = 0; i == 0 || i % S.size() || i % T.size(); ++i) {
		if (S[i % S.size()] != T[i % T.size()]) {
			yes = false;
			break;
		}
	}
	cout << yes << "\n";
	return 0;
}
