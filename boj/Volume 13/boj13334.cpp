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
		cin >> u >> v;
		if (u > v) {
			swap(u, v);
		}
	}
	int D{};
	cin >> D;
	vector<ii> B;
	for (auto &[u, v] : A) {
		if (v - u > D) {
			continue;
		}
		B.push_back({v, 0});
		B.push_back({u + D, 1});
	}
	sort(B.begin(), B.end());
	int ans{}, cnt{};
	for (auto &[u, v] : B) {
		cnt += v ? -1 : 1;
		ans = max(ans, cnt);
	}
	cout << ans << "\n";
	return 0;
}
