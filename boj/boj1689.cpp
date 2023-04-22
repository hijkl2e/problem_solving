#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ii> A;
	while (N--) {
		int s{}, e{};
		cin >> s >> e;
		A.push_back({s, 1});
		A.push_back({e, -1});
	}
	sort(A.begin(), A.end());
	int ans{}, cnt{};
	for (auto &p : A) {
		cnt += p.second;
		ans = max(ans, cnt);
	}
	cout << ans << "\n";
	return 0;
}
