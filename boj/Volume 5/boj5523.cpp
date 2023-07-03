#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int x{}, y{};
	while (N--) {
		int a{}, b{};
		cin >> a >> b;
		if (a > b) {
			++x;
		} else if (a < b) {
			++y;
		}
	}
	cout << x << " " << y << "\n";
	return 0;
}
