#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ii> A;
	ll c1{}, c2{}, c3{};
	for (int i = 0; i < N; ++i) {
		int x{}, y{};
		cin >> x >> y;
		if (x && y) {
			int g = gcd(x, y);
			A.push_back({x / g, y / g});
		} else if (x == 0 && y == 0) {
			++c1;
		} else if (x == 0) {
			++c2;
		} else {
			++c3;
		}
	}
	ll ans = N * c1 - c1 * (c1 + 1) / 2 + c2 * c3;
	map<ii, int> freq;
	for (int i = 0; i < A.size(); ++i) {
		auto &[x, y] = A[i];
		int n = y, d = x;
		if (d < 0) {
			n *= -1, d *= -1;
		}
		ans += freq[{n, d}];
		n = x, d = -y;
		if (d < 0) {
			n *= -1, d *= -1;
		}
		++freq[{n, d}];
	}
	cout << ans << "\n";
	return 0;
}
