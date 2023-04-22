#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, x{}, y{};
	cin >> N;
	while (N-- && abs(x - y) < 2) {
		char c{};
		cin >> c;
		if (c == 'D') {
			++x;
		} else {
			++y;
		}
	}
	cout << x << ":" << y << "\n";
	return 0;
}
