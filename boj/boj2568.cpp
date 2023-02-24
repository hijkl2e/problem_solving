#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(500001);
	for (int i = 0; i < N; ++i) {
		int x{}, y{};
		cin >> x >> y;
		A[x] = y;
	}
	vector<int> dp;
	stack<ii> st;
	for (int i = 1; i < A.size(); ++i) {
		if (A[i] == 0) {
			continue;
		}
		int j = lower_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
		if (j == dp.size()) {
			dp.push_back(A[i]);
		} else {
			dp[j] = A[i];
		}
		st.push({j, i});
	}
	int cnt{};
	while (st.size()) {
		auto [x, y] = st.top(); st.pop();
		if (x == dp.size() - cnt - 1) {
			A[y] = 0;
			++cnt;
		}
	}
	cout << N - cnt << "\n";
	for (int i = 1; i < A.size(); ++i) {
		if (A[i]) {
			cout << i << "\n";
		}
	}
	return 0;
}
