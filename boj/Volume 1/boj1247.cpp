#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 3;
	while (T--) {
		int N{};
		cin >> N;
		__int128 sum{};
		while (N--) {
			ll x{};
			cin >> x;
			sum += x;
		}
		cout << (sum > 0 ? "+" : sum < 0 ? "-" : "0") << "\n";
	}
	return 0;
}
