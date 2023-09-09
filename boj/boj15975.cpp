#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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
	ll ans{};
	for (int i = 1; i <= N; ++i) {
		auto &v = A[i];
		if (v.size() < 2) {
			continue;
		}
		sort(v.begin(), v.end());
		for (int j = 0; j < v.size(); ++j) {
			ans += min(j + 1 < v.size() ? v[j + 1] - v[j] : INF, j ? v[j] - v[j - 1] : INF);
		}
	}
	cout << ans << "\n";
	return 0;
}
