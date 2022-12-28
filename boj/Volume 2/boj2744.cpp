#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	for (auto &c : S) {
		c ^= 32;
	}
	cout << S << "\n";
	return 0;
}
