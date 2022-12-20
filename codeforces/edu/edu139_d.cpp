#include <bits/stdc++.h>

using namespace std;

vector<int> sieve() {
	vector<int> p(10000001);
	for (int i = 0; i < p.size(); ++i) {
		p[i] = i;
	}
	for (int i = 2; i < p.size(); ++i) {
		if (p[i] == i) {
			for (int j = 2 * i; j < p.size(); j += i) {
				p[j] = i;
			}
		}
	}
	return p;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> P = sieve();
	int T{};
	cin >> T;
	while (T--) {
		int x{}, y{};
		cin >> x >> y;
		int d = y - x;
		if (d == 1) {
			cout << "-1\n";
			continue;
		}
		int ans = 1e9;
		while (d > 1) {
			ans = min(ans, (P[d] - (x % P[d])) % P[d]);
			d /= P[d];
		}
		cout << ans << "\n";
	}
	return 0;
}
