#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{};
	cin >> a >> b;
	for (int i = 0; a < 5 && b < 5; ++i) {
		if (i % 2) {
			a += b;
		} else {
			b += a;
		}
	}
	cout << (a < b ? "yt" : "yj") << "\n";
	return 0;
}
