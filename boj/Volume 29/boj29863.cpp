#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{};
	cin >> a >> b;
	a = (a + 4) % 24;
	b = (b + 4) % 24;
	cout << b - a << "\n";
	return 0;
}
