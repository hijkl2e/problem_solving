#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{}, d{}, e{}, f{};
	cin >> a >> b >> c >> d >> e >> f;
	int x = 3 * a + 2 * b + c;
	int y = 3 * d + 2 * e + f;
	cout << (x > y ? "A" : x < y ? "B" : "T") << "\n";
	return 0;
}
