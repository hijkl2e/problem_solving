#include <bits/stdc++.h>

using namespace std;

bool solve(string &s, char c) {
	for (int i = 0; i < 3; ++i) {
		if ((s[3 * i] == c && s[3 * i + 1] == c && s[3 * i + 2] == c)
				|| (s[i] == c && s[i + 3] == c && s[i + 6] == c)) {
			return true;
		}
	}
	return s[4] == c && ((s[0] == c && s[8] == c) || (s[2] == c && s[6] == c));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	while (getline(cin, S), S != "end") {
		bool x_win = solve(S, 'X');
		bool o_win = solve(S, 'O');
		int x_cnt = count(S.begin(), S.end(), 'X');
		int o_cnt = count(S.begin(), S.end(), 'O');
		bool yes = (x_win ^ o_win) && ((x_win && x_cnt == o_cnt + 1) || (o_win && o_cnt == x_cnt));
		yes |= !x_win && !o_win && x_cnt == 5 && o_cnt == 4;
		cout << (yes ? "valid" : "invalid") << "\n";
	}
	return 0;
}
