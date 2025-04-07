#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int K{};
		cin >> K;
		multiset<int> S;
		while (K--) {
			char c{};
			int x{};
			cin >> c >> x;
			if (c == 'I') {
				S.insert(x);
				continue;
			} else if (S.empty()) {
				continue;
			}
			if (x == 1) {
				S.erase(--S.end());
			} else {
				S.erase(S.begin());
			}
		}
		if (S.empty()) {
			cout << "EMPTY\n";
		} else {
			cout << *--S.end() << " " << *S.begin() << "\n";
		}
	}
	return 0;
}
