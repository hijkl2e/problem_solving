#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int now = 11;
	bool dir = true;
	while (N--) {
		string s;
		int x{};
		cin >> s >> x;
		now = (now + (dir ? 1 : 11)) % 12;
		bool yes{};
		if (s == "HOURGLASS") {
			if (now + 1 != x) {
				dir ^= true;
			}
		} else if (now + 1 == x) {
			yes = true;
		}
		cout << now + 1 << " " << (yes ? "YES" : "NO") << "\n";
	}
	return 0;
}
