#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		ll N{}, P{};
		cin >> N >> P;
		ll x{}, y{};
		cin >> x;
		while (--N) {
			cin >> y;
		}
		cout << (x % (P + 1) ? "First" : "Second") << "\n";
	}
	return 0;
}
