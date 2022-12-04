#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		char c{};
		int D{}, H{}, M{};
		cin >> c >> D >> H >> M;
		int time = 60 * H + M;
		if (c == 'B') {
			D = -D;
		}
		time = (time + D + 1440) % 1440;
		H = time / 60;
		M = time % 60;
		cout << H << " " << M << "\n";
	}
	return 0;
}
