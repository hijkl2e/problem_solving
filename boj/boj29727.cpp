#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int x1{}, y1{}, x2{}, y2{};
	cin >> x1 >> y1 >> x2 >> y2;
	if (x1 == x2) {
		swap(x1, y1);
		swap(x2, y2);
	}
	ll ans = 1LL * N * (N + 1) * N * (N + 1) / 4;
	if (y1 == y2) {
		if (x1 > x2) {
			swap(x1, x2);
		}
		int M = max(min(x2, N) - max(x1 + 1, 0), 0);
		ans += 1LL * (N + 1) * M * (M + 1) / 2;
	}
	cout << ans << "\n";
	return 0;
}
