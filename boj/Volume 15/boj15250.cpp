#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll mod1 = 1e9 + 7;
const ll mod2 = 1e9 + 9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		string S;
		getline(cin, S);
		int s = 0, e = S.size() - 1;
		int ans{};
		while (s <= e) {
			if (s == e) {
				++ans;
				break;
			}
			ll x1{}, y1{}, x2{}, y2{}, p1{}, p2{};
			p1 = p2 = 1;
			do {
				x1 = (131 * x1 + S[s]) % mod1;
				y1 = (131 * y1 + S[s]) % mod2;
				x2 = (x2 + p1 * S[e]) % mod1;
				y2 = (y2 + p2 * S[e]) % mod2;
				p1 = 131 * p1 % mod1;
				p2 = 131 * p2 % mod2;
			} while (++s < --e && (x1 != x2 || y1 != y2));
			if (x1 == x2 && y1 == y2) {
				ans += 2;
			} else {
				++ans;
				break;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
