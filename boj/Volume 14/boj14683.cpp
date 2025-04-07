#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{}, d{}, t{};
	cin >> a >> b >> c >> d >> t;
	int dist = abs(c - a) + abs(d - b);
	bool yes = dist <= t && (dist + t) % 2 == 0;
	cout << (yes ? "Y" : "N") << "\n";
	return 0;
}
