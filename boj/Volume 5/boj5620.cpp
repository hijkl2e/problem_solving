#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;

int square(int x) {
	return x * x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ii> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first >> A[i].second;
	}
	sort(A.begin(), A.end());
	set<ii> S;
	int ans = INF;
	for (auto &[x, y] : A) {
		int d = sqrt(ans);
		auto it = S.lower_bound({y - d, -INF});
		while (it != S.end() && it->first <= y + d) {
			if (x - it->second > d) {
				it = S.erase(it);
			} else {
				ans = min(ans, square(x - it->second) + square(y - it->first));
				++it;
			}
		}
		S.insert({y, x});
	}
	cout << ans << "\n";
	return 0;
}
