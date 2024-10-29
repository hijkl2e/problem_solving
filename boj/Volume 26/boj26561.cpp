#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		ll p{}, t{};
		cin >> p >> t;
		p -= t / 7;
		p += t / 4;
		cout << p << "\n";
	}
	return 0;
}
