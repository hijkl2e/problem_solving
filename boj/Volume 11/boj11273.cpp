#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<multiset<int>> A(10001);
	int G{};
	cin >> G;
	while (G--) {
		int x{}, y{};
		cin >> x >> y;
		A[x].insert(y);
	}
	int M{};
	cin >> M;
	while (M--) {
		int x{}, y{}, r{};
		cin >> x >> y >> r;
		for (int i = -r; i <= r; ++i) {
			if (x + i < 0 || x + i >= A.size()) {
				continue;
			}
			auto &s = A[x + i];
			int d{};
			while ((d + 1) * (d + 1) + i * i <= r * r) {
				++d;
			}
			auto it = s.lower_bound(y - d);
			while (it != s.end() && *it <= y + d) {
				it = s.erase(it);
			}
		}
	}
	int ans{};
	for (int i = 0; i < A.size(); ++i) {
		ans += A[i].size();
	}
	cout << ans << "\n";
	return 0;
}
