#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(N + 1);
	for (int i = 0; i < N; ++i) {
		int x{}, y{};
		cin >> x >> y;
		A[y].push_back(x);
	}
	for (int i = 1; i <= N; ++i) {
		sort(A[i].begin(), A[i].end());
	}
	int ans{};
	for (int i = 1; i <= N; ++i) {
		auto &v = A[i];
		if (v.empty()) {
			continue;
		}
		for (int j = 0; j < v.size(); ++j) {
			ans += min(j ? v[j] - v[j - 1] : INF, j + 1 < v.size() ? v[j + 1] - v[j] : INF);
		}
	}
	cout << ans << "\n";
	return 0;
}
