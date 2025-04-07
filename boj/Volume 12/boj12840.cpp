#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int h{}, m{}, s{};
	cin >> h >> m >> s;
	int T = 3600 * h + 60 * m + s;
	int Q{};
	cin >> Q;
	while (Q--) {
		int q{};
		cin >> q;
		if (q == 3) {
			cout << T / 3600 << " " << T / 60 % 60 << " " << T % 60 << "\n";
		} else {
			int c{};
			cin >> c;
			if (q == 1) {
				T = (T + c) % 86400;
			} else {
				T = ((T - c) % 86400 + 86400) % 86400;
			}
		}
	}
	return 0;
}
