#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int L{}, N{};
		cin >> L >> N;
		int minv{}, maxv{};
		while (N--) {
			int x{};
			cin >> x;
			minv = max(minv, min(x, L - x));
			maxv = max(maxv, max(x, L - x));
		}
		cout << minv << " " << maxv << "\n";
	}
	return 0;
}
