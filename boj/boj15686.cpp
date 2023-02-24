#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<ii> A, B;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int x{};
			cin >> x;
			if (x == 1) {
				A.push_back({i, j});
			} else if (x == 2) {
				B.push_back({i, j});
			}
		}
	}
	int ans = INF;
	for (int i = 0; i < (1 << B.size()); ++i) {
		if (__builtin_popcount(i) != M) {
			continue;
		}
		int sum{};
		for (auto &[x1, y1] : A) {
			int minv = INF;
			for (int j = 0; j < B.size(); ++j) {
				if (i & (1 << j)) {
					auto &[x2, y2] = B[j];
					minv = min(minv, abs(x2 - x1) + abs(y2 - y1));
				}
			}
			sum += minv;
		}
		ans = min(ans, sum);
	}
	cout << ans << "\n";
	return 0;
}
