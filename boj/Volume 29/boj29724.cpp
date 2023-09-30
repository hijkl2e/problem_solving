#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int g{}, x{};
	while (N--) {
		int w{}, h{}, l{};
		char t{};
		cin >> t >> w >> h >> l;
		if (t == 'A') {
			int y = (w / 12) * (h / 12) * (l / 12);
			x += y;
			g += 500 * y + 1000;
		} else {
			g += 6000;
		}
	}
	cout << g << "\n";
	cout << 4000 * x << "\n";
	return 0;
}
