#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	for (int tc = 0; cin >> N, N; ++tc) {
		if (tc) {
			cout << "\n";
		}
		int x{}, y{};
		while (N--) {
			string cmd;
			int M{};
			cin >> cmd >> M;
			if (cmd == "DROP") {
				cout << "DROP 2 " << M << "\n";
				y += M;
				continue;
			}
			if (x) {
				int minv = min(x, M);
				cout << "TAKE 1 " << minv << "\n";
				x -= minv;
				M -= minv;
				if (M == 0) {
					continue;
				}
			}
			if (!x && y) {
				cout << "MOVE 2->1 " << y << "\n";
				x = y;
				y = 0;
			}
			if (M) {
				cout << "TAKE 1 " << M << "\n";
				x -= M;
			}
		}
	}
	return 0;
}
