#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		ll x{}, y{}, z{};
		char c1{}, c2{};
		cin >> x >> c1 >> y >> c2 >> z;
		bool yes{};
		yes |= c1 == '+' && x + y == z;
		yes |= c1 == '-' && x - y == z;
		yes |= c1 == '*' && x * y == z;
		yes |= c1 == '/' && x / y == z;
		cout << (yes ? "correct" : "wrong answer") << "\n";
	}
	return 0;
}
