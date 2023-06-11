#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	getline(cin, s);
	if (next_permutation(s.begin(), s.end())) {
		cout << s << "\n";
	} else {
		cout << "0\n";
	}
	return 0;
}
