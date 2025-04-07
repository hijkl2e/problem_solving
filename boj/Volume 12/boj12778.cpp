#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		char c{};
		cin >> N >> c;
		if (c == 'C') {
			while (N--) {
				cin >> c;
				cout << (c - 'A' + 1) << (N ? " " : "\n");
			}
		} else {
			while (N--) {
				int x{};
				cin >> x;
				c = x + 'A' - 1;
				cout << c << (N ? " " : "\n");
			}
		}
	}
	return 0;
}
