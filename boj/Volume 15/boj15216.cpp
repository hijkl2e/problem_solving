#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int H{}, W{}, N{};
	cin >> H >> W >> N;
	int h{}, w{};
	bool yes = false;
	while (N--) {
		int x{};
		cin >> x;
		if (w + x == W) {
			if (++h == H) {
				yes = true;
				break;
			}
			w = 0;
		} else if (w + x < W) {
			w += x;
		} else {
			break;
		}
	}
	cout << (yes ? "YES" : "NO") << "\n";
	return 0;
}
