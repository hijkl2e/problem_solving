#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	for (auto &c : S) {
		c = toupper(c);
	}
	cout << S << "\n";
	return 0;
}
