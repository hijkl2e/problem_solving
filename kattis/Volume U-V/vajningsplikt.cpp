#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string A, B, C;
	cin >> A >> B >> C;
	map<string, int> d2i{
		{"East", 0}, {"South", 1}, {"West", 2}, {"North", 3}
	};
	int a{}, b{}, c{};
	a = d2i[A];
	b = d2i[B];
	c = d2i[C];
	bool yes = b == (a + 2) % 4 && c == (a + 3) % 4;
	yes |= b == (a + 1) % 4 && c != (a + 1) % 4;
	cout << (yes ? "Yes" : "No") << "\n";
	return 0;
}
