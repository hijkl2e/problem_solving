#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, 0, -1, 0};
const int dy[4]{0, -1, 0, 1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{}, N{};
	cin >> M >> N;
	int x{}, y{}, d{};
	while (N--) {
		string cmd;
		int k{};
		cin >> cmd >> k;
		if (cmd == "TURN") {
			d = (d + (k ? 1 : 3)) % 4;
		} else {
			x += k * dx[d];
			y += k * dy[d];
			if (x < 0 || x > M || y < 0 || y > M) {
				cout << "-1\n";
				return 0;
			}
		}
	}
	cout << x << " " << y << "\n";
	return 0;
}
