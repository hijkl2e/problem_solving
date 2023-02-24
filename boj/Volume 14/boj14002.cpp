#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> dp(N, 1);
	vector<int> par(N, -1);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			if (A[j] < A[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				par[i] = j;
			}
		}
	}
	int x = max_element(dp.begin(), dp.end()) - dp.begin();
	stack<int> st;
	st.push(x);
	while (par[x] != -1) {
		x = par[x];
		st.push(x);
	}
	cout << st.size() << "\n";
	while (st.size()) {
		x = st.top(); st.pop();
		cout << A[x] << (st.empty() ? "\n" : " ");
	}
	return 0;
}
