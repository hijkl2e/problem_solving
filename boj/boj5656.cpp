#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{};
	string op;
	for (int tc = 1; cin >> a >> op >> b, op != "E"; ++tc) {
		bool yes{};
		yes |= op == ">" && a > b;
		yes |= op == ">=" && a >= b;
		yes |= op == "<" && a < b;
		yes |= op == "<=" && a <= b;
		yes |= op == "==" && a == b;
		yes |= op == "!=" && a != b;
		cout << "Case " << tc << ": " << (yes ? "true" : "false") << "\n";
	}
	return 0;
}
