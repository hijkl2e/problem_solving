#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{};
	while (cin >> K, K) {
		int M{};
		cin >> M;
		set<int> S;
		while (K--) {
			int x{};
			cin >> x;
			S.insert(x);
		}
		bool yes = true;
		while (M--) {
			int c{}, r{};
			cin >> c >> r;
			int cnt{};
			while (c--) {
				int x{};
				cin >> x;
				if (S.count(x)) {
					++cnt;
				}
			}
			if (cnt < r) {
				yes = false;
			}
		}
		cout << (yes ? "yes" : "no") << "\n";
	}
	return 0;
}
