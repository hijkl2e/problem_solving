#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int y{}, m{}, d{}, N{};
	char c{};
	cin >> y >> c >> m >> c >> d >> N;
	int t = 360 * y + 30 * (m - 1) + (d - 1) + N;
	y = t / 360;
	m = t / 30 % 12 + 1;
	d = t % 30 + 1;
	cout << setfill('0');
	cout << y << "-" << setw(2) << m << "-" << setw(2) << d << "\n";
	return 0;
}
