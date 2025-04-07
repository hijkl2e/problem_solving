#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{};
	cin >> a >> b >> c;
	bool f = a == b || b == c || c == a || a + b == c || b + c == a || c + a == b;
	cout << (f ? "S" : "N") << "\n";
	return 0;
}
