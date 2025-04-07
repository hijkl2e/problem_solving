#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		ll sum{};
		for (int i = 0; i < N; ++i) {
			ll x{};
			cin >> x;
			sum += x % N;
		}
		cout << (sum % N == 0 ? "YES" : "NO") << "\n";
	}
	return 0;
}
