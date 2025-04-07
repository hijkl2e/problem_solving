#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S, T;
	getline(cin, S);
	bool flag{};
	for (char c : S) {
		if (flag) {
			cout << c;
			if (c == '>') {
				flag = false;
			}
		} else if (c == ' ' || c == '<') {
			reverse(T.begin(), T.end());
			cout << T << c;
			T.clear();
			flag = c == '<';
		} else {
			T += c;
		}
	}
	reverse(T.begin(), T.end());
	cout << T << "\n";
	return 0;
}
