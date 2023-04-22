#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int X{}, Y{};
	X = Y = 100;
	while (N--) {
		int x{}, y{};
		cin >> x >> y;
		if (x > y) {
			Y -= x;
		} else if (x < y) {
			X -= y;
		}
	}
	cout << X << "\n" << Y << "\n";
	return 0;
}
