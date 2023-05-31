#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	int x{}, y{};
	while (cin >> s >> x >> y, s != "#") {
		cout << s << " " << (x > 17 || y >= 80 ? "Senior" : "Junior") << "\n";
	}
	return 0;
}
