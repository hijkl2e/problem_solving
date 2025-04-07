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
		int s{}, t{};
		cin >> s >> t;
		A.push_back({s, 1});
		A.push_back({t, -1});
	}
	sort(A.begin(), A.end());
	int ans{}, cnt{};
	for (int i = 0; i < A.size(); ++i) {
		cnt += A[i].second;
		ans = max(ans, cnt);
	}
	cout << ans << "\n";
	return 0;
}
