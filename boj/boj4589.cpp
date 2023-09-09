#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cout << "Gnomes:\n";
	while (T--) {
		int a{}, b{}, c{};
		cin >> a >> b >> c;
		cout << ((a < b && b < c) || (a > b && b > c) ? "Ordered" : "Unordered") << "\n";
	}
	return 0;
}
