#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, x{};
	cin >> N >> x;
	if (N < 6) {
		while (--N) {
			x ^= 1;
			cout << x << "\n";
		}
	} else {
		cout << "Love is open door\n";
	}
	return 0;
}
