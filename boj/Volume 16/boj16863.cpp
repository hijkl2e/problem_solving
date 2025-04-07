#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int H{}, A{}, x{}, prev{};
	while (N--) {
		char c{};
		int p{}, m{}, s{};
		cin >> c >> p;
		if (c == 'A') {
			p = -p;
		}
		cin >> m >> c >> s;
		int now = 60 * m + s;
		if (x > 0) {
			H += now - prev;
		} else if (x < 0) {
			A += now - prev;
		}
		x += p;
		prev = now;
	}
	char winner{};
	if (x > 0) {
		winner = 'H';
		H += 32 * 60 - prev;
	} else if (x < 0) {
		winner = 'A';
		A += 32 * 60 - prev;
	}
	cout << winner << " " << setfill('0');
	cout << H / 60 << ":" << setw(2) << H % 60 << " ";
	cout << A / 60 << ":" << setw(2) << A % 60 << "\n";
	return 0;
}
