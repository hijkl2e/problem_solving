#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int x{};
	for (char c : S) {
		x += c == 'B' ? 1 : -1;
	}
	cout << !x << "\n";
	return 0;
}
