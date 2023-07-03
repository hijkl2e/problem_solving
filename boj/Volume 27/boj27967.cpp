#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	int c1{}, c2{};
	for (char c : S) {
		if (c == 'G') {
			++c1;
		} else {
			c2 += c == '(' ? 1 : -1;
		}
	}
	c2 = (c1 - c2) / 2;
	for (char &c : S) {
		if (c == 'G') {
			if (c2 > 0) {
				c = '(';
				--c2;
			} else {
				c = ')';
			}
		}
	}
	cout << S << "\n";
	return 0;
}
