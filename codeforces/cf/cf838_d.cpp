#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		int x = 1, y = 2;
		for (int i = 3; i <= N; ++i) {
			cout << "? " << x << " " << i << endl;
			cout << "? " << y << " " << i << endl;
			int gx{}, gy{};
			cin >> gx >> gy;
			if (gx < gy) {
				x = i;
			} else if (gx > gy) {
				y = i;
			}
		}
		cout << "! " << x << " " << y << endl;
		cin >> x;
	}
	return 0;
}
