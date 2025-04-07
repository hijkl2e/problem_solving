#include <bits/stdc++.h>

using namespace std;

int solve(int n, int x, int t) {
	t %= 2 * n;
	int y = min(n - x, t);
	x += y, t -= y;
	y = min(n, t);
	x -= y, t -= y;
	return x + t;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int w{}, h{}, p{}, q{}, t{};
	cin >> w >> h >> p >> q >> t;
	cout << solve(w, p, t) << " " << solve(h, q, t) << "\n";
	return 0;
}
