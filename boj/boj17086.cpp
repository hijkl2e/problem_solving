#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<ii> A;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int x{};
			cin >> x;
			if (x) {
				A.push_back({i, j});
			}
		}
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int minv = INF;
			for (auto &p : A) {
				minv = min(minv, max(abs(i - p.first), abs(j - p.second)));
			}
			ans = max(ans, minv);
		}
	}
	cout << ans << "\n";
	return 0;
}
