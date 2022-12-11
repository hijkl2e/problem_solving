#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int X{}, Y{};
		cin >> X >> Y;
		double h = ((X + Y) - sqrt(X * X + Y * Y - X * Y)) / 6;
		double a = X - 2 * h;
		double b = Y - 2 * h;
		cout << fixed << setprecision(10);
		cout << a * b * h << "\n";
	}
	return 0;
}
