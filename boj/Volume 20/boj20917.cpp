#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, C{};
		cin >> N >> C;
		vector<int> x(N);
		for (int i = 0; i < N; ++i) {
			cin >> x[i];
		}
		sort(x.begin(), x.end());
		int lo = 1, hi = 1e9 + 7;
		while (lo + 1 < hi) {
			int mid = (lo + hi) / 2;
			int cnt{};
			for (int i = 0, j = 1; i < N; i = j++) {
				while (j < N && x[j] - x[i] < mid) {
					++j;
				}
				++cnt;
			}
			if (cnt < C) {
				hi = mid;
			} else {
				lo = mid;
			}
		}
		cout << lo << "\n";
	}
	return 0;
}
