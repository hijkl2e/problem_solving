#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int c{}, v{};
		cin >> c >> v;
		cout << "You get " << c / v << " piece(s) and your dad gets " << c % v << " piece(s).\n";
	}
	return 0;
}
