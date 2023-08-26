#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int d{}, h{}, m{};
	cin >> d >> h >> m;
	int t = 1440 * (d - 11) + 60 * (h - 11) + (m - 11);
	cout << (t < 0 ? -1 : t) << "\n";
	return 0;
}
