#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, xh{}, yh{}, xw{}, yw{};
	cin >> N >> xh >> yh >> xw >> yw;
	vector<ii> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first >> A[i].second;
	}
	if (xh > xw) {
		xh *= -1, xw *= -1;
		for (int i = 0; i < N; ++i) {
			A[i].first *= -1;
		}
	}
	if (yh > yw) {
		yh *= -1, yw *= -1;
		for (int i = 0; i < N; ++i) {
			A[i].second *= -1;
		}
	}
	vector<ii> B;
	for (auto &[x, y] : A) {
		if (xh <= x && x <= xw && yh <= y && y <= yw) {
			B.push_back({x, y});
		}
	}
	sort(B.begin(), B.end());
	vector<int> dp;
	for (int i = 0; i < B.size(); ++i) {
		int j = upper_bound(dp.begin(), dp.end(), B[i].second) - dp.begin();
		if (j == dp.size()) {
			dp.push_back(B[i].second);
		} else {
			dp[j] = B[i].second;
		}
	}
	cout << dp.size() << "\n";
	return 0;
}
