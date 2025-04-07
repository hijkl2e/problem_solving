#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int o{}, w{};
	for (int tc = 1; cin >> o >> w, o; ++tc) {
		char c{};
		int n{};
		while (cin >> c >> n, c != '#') {
			if (w > 0) {
				w += (c == 'E' ? -1 : 1) * n;
			}
		}
		cout << tc << " " << (2 * w > o && w < 2 * o ? ":-)" : w > 0 ? ":-(" : "RIP") << "\n";
	}
	return 0;
}
