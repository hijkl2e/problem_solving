#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int a{}, b{}, c{};
		cin >> a >> b >> c;
		bool yes = false;
		yes |= a + b == c;
		yes |= a - b == c;
		yes |= b - a == c;
		yes |= a * b == c;
		yes |= a % b == 0 && a / b == c;
		yes |= b % a == 0 && b / a == c;
		cout << (yes ? "Possible" : "Impossible") << "\n";
	}
	return 0;
}
