#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	for (int tc = 1; cin >> N; ++tc) {
		int minv = 1e9;
		int maxv = -1e9;
		while (N--) {
			int x{};
			cin >> x;
			minv = min(minv, x);
			maxv = max(maxv, x);
		}
		cout << "Case " << tc << ": " << minv << " " << maxv << " " << (maxv - minv) << "\n";
	}
	return 0;
}
