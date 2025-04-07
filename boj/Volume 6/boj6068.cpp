#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ii> A(N);
	for (auto &[u, v] : A) {
		cin >> v >> u;
	}
	sort(A.rbegin(), A.rend());
	int ans = 1e9;
	for (auto &[u, v] : A) {
		ans = min(ans, u) - v;
	}
	ans = max(ans, -1);
	cout << ans << "\n";
	return 0;
}
