#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int len = S.size() / 3;
	for (int i = 0; i < len; ++i) {
		cout << (S[i] == S[i + len] ? S[i] : S[i + 2 * len]);
	}
	cout << "\n";
	return 0;
}
