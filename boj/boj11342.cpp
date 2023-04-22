#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		string S;
		getline(cin, S);
		istringstream iss(S);
		int s{}, p{}, ans{};
		char c{};
		for (int f = 1; iss >> c;) {
			if (c == 'X') {
				ans += (s + p + 1) * 10;
				p = s;
				s = f++ < 10;
				continue;
			}
			int x = c - '0';
			ans += (s + p + 1) * x;
			p = s;
			s = 0;
			if (iss >> c) {
				int y = c == '/' ? (10 - x) : (c - '0');
				ans += (p + 1) * y;
				p = f++ < 10 && y == 10 - x;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
