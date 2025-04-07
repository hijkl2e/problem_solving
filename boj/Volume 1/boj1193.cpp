#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int X{}, Y{};
	cin >> X;
	while (X > ++Y) {
		X -= Y;
	}
	if (Y % 2) {
		X = Y - X + 1;
	}
	cout << X << "/" << (Y - X + 1) << "\n";
	return 0;
}
