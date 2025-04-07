#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S, T;
	getline(cin, S);
	getline(cin, T);
	string U = S;
	reverse(U.begin(), U.end());
	bool yes = S + string(T.size() - S.size(), 'A') == T;
	if (T[0] == 'B') {
		for (int i = 1; i + S.size() <= T.size(); ++i) {
			int x = count(T.begin(), T.begin() + i, 'B');
			x -= count(T.begin() + i + S.size(), T.end(), 'B');
			if (T.substr(i, S.size()) == (x == 0 ? S : x == 1 ? U : "")) {
				yes = true;
				break;
			}
		}
	}
	cout << yes << "\n";
	return 0;
}
