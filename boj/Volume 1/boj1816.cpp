#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		ll x{};
		cin >> x;
		bool yes = true;
		for (int i = 2; i < 1000000; ++i) {
			if (x % i == 0) {
				yes = false;
				break;
			}
		}
		cout << (yes ? "YES" : "NO") << "\n";
	}
	return 0;
}
