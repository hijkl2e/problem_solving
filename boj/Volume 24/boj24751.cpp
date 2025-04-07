#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	double A{};
	cin >> A;
	double x = 1 + (100 - A) / A;
	double y = 1 + A / (100 - A);
	cout << fixed << setprecision(10);
	cout << x << "\n" << y << "\n";
	return 0;
}
