#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{}, d{};
	while (cin >> a >> b >> c >> d, a || b || c || d) {
		cout << c - b << " " << d - a << "\n";
	}
	return 0;
}
