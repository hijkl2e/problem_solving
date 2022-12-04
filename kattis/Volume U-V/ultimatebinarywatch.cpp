#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			int x = S[j] - '0';
			cout << (x & (1 << (3 - i)) ? '*' : '.');
			cout << (j == 3 ? "\n" : j == 1 ? "   " : " ");
		}
	}
	return 0;
}
