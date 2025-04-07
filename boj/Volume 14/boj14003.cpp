#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> dp;
	stack<ii> st;
	for (int i = 0; i < N; ++i) {
		int j = lower_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
		if (j == dp.size()) {
			dp.push_back(A[i]);
		} else {
			dp[j] = A[i];
		}
		st.push({j, i});
	}
	vector<int> B;
	while (st.size()) {
		auto [x, y] = st.top(); st.pop();
		if (x == dp.size() - B.size() - 1) {
			B.push_back(A[y]);
		}
	}
	reverse(B.begin(), B.end());
	cout << B.size() << "\n";
	for (int i = 0; i < B.size(); ++i) {
		cout << B[i] << (i == B.size() - 1 ? "\n" : " ");
	}
	return 0;
}
