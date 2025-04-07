#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int x = -1;
	while (N--) {
		if (x == -1) {
			cin >> x;
			continue;
		}
		int y{};
		cin >> y;
		if (y % x == 0) {
			cout << y << "\n";
			x = -1;
		}
	}
	return 0;
}
