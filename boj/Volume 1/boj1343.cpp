#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	for (int i = 0; i < S.size(); ++i) {
		if (S[i] == '.') {
			continue;
		}
		int x = -1;
		if (i + 3 < S.size() && accumulate(S.begin() + i, S.begin() + i + 4, 0) == 4 * 'X') {
			x = 4;
		} else if (i + 1 < S.size() && S[i] + S[i + 1] == 2 * 'X') {
			x = 2;
		} else {
			S = "-1";
			break;
		}
		fill(S.begin() + i, S.begin() + i + x, x == 4 ? 'A' : 'B');
		i += x - 1;
	}
	cout << S << "\n";
	return 0;
}
