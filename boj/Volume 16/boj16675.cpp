#include <bits/stdc++.h>

using namespace std;

bool win(char c1, char c2) {
	return (c1 == 'S' && c2 == 'P') || (c1 == 'R' && c2 == 'S') || (c1 == 'P' && c2 == 'R');
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	char a{}, b{}, c{}, d{};
	cin >> a >> b >> c >> d;
	string ans = "?";
	if (c == d && (win(a, c) || win(b, c))) {
		ans = "MS";
	}
	if (a == b && (win(c, a) || win(d, a))) {
		ans = "TK";
	}
	cout << ans << "\n";
	return 0;
}
