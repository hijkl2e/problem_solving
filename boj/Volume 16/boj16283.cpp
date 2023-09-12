#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, n{}, w{};
	cin >> a >> b >> n >> w;
	int x = -1;
	for (int i = 1; i < n; ++i) {
		if (i * a + (n - i) * b == w) {
			if (x == -1) {
				x = i;
			} else {
				x = -1;
				break;
			}
		}
	}
	if (x == -1) {
		cout << "-1\n";
	} else {
		cout << x << " " << (n - x) << "\n";
	}
	return 0;
}
