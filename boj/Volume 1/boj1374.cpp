#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ii> A;
	for (int i = 0; i < N; ++i) {
		int n{}, s{}, e{};
		cin >> n >> s >> e;
		A.push_back({s, 1});
		A.push_back({e, 0});
	}
	sort(A.begin(), A.end());
	int ans{}, cnt{};
	for (auto &[u, v] : A) {
		cnt += v ? 1 : -1;
		ans = max(ans, cnt);
	}
	cout << ans << "\n";
	return 0;
}
