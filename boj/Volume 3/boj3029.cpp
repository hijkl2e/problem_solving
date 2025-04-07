#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int h{}, m{}, s{};
	char c{};
	cin >> h >> c >> m >> c >> s;
	int t1 = 3600 * h + 60 * m + s;
	cin >> h >> c >> m >> c >> s;
	int t2 = 3600 * h + 60 * m + s;
	int diff = (t2 - t1 + 86400) % 86400;
	if (diff == 0) {
		diff = 86400;
	}
	h = diff / 3600;
	m = diff % 3600 / 60;
	s = diff % 60;
	cout << setfill('0');
	cout << setw(2) << h << ":" << setw(2) << m << ":" << setw(2) << s << "\n";
	return 0;
}
