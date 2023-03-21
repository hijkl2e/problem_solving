#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	map<ii, int> freq;
	while (N--) {
		int x{}, y{};
		cin >> x >> y;
		for (int i = 0; i < K; ++i) {
			int z = i * M + (i % 2 ? (M - x) : x);
			int g = gcd(z, y);
			++freq[{z / g, y / g}];
		}
	}
	int ans{};
	for (auto &p : freq) {
		ans = max(ans, p.second);
	}
	cout << ans << "\n";
	return 0;
}
