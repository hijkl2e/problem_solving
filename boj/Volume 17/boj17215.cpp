#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int s{}, p{}, ans{};
	for (int i = 0, f = 1; i < S.size(); ++i) {
		if (S[i] == 'S') {
			ans += (s + p + 1) * 10;
			p = s;
			s = f++ < 10;
			continue;
		}
		int x = S[i] == '-' ? 0 : (S[i] - '0');
		ans += (s + p + 1) * x;
		p = s;
		s = 0;
		if (++i < S.size()) {
			int y = S[i] == 'P' ? (10 - x) : S[i] == '-' ? 0 : (S[i] - '0');
			ans += (p + 1) * y;
			p = f++ < 10 && y == 10 - x;
		}
	}
	cout << ans << "\n";
	return 0;
}
