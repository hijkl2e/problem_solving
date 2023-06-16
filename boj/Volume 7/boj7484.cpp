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
		int x{}, s{}, p{}, ans{};
		for (int f = 1; iss >> x;) {
			if (x == 10) {
				ans += (s + p + 1) * 10;
				p = s;
				s = f++ < 10;
				continue;
			}
			ans += (s + p + 1) * x;
			p = s;
			s = 0;
			int y{};
			if (iss >> y) {
				ans += (p + 1) * y;
				p = f++ < 10 && y == 10 - x;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
