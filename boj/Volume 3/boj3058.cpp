#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int sum{}, minv = 1e9;
		for (int i = 0; i < 7; ++i) {
			int x{};
			cin >> x;
			if (x % 2 == 0) {
				sum += x;
				minv = min(minv, x);
			}
		}
		cout << sum << " " << minv << "\n";
	}
	return 0;
}
