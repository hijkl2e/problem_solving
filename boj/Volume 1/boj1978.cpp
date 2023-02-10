#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans{};
	while (N--) {
		int x{};
		cin >> x;
		bool yes = x > 1;
		for (int i = 2; i * i <= x; ++i) {
			if (x % i == 0) {
				yes = false;
				break;
			}
		}
		if (yes) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
