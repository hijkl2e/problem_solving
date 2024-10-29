#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	vector<int> C(N + 1);
	for (int i = 0; i < N; ++i) {
		C[B[i]] = i;
	}
	vector<int> D(N);
	for (int i = 0; i < N; ++i) {
		D[i] = C[A[i]];
	}
	vector<int> dp;
	stack<ii> st;
	for (int i = 0; i < N; ++i) {
		int j = lower_bound(dp.begin(), dp.end(), D[i]) - dp.begin();
		if (j == dp.size()) {
			dp.push_back(D[i]);
		} else {
			dp[j] = D[i];
		}
		st.push({j, A[i]});
	}
	vector<int> E;
	while (st.size()) {
		auto [x, y] = st.top(); st.pop();
		if (x == dp.size() - E.size() - 1) {
			E.push_back(y);
		}
	}
	sort(E.begin(), E.end());
	cout << E.size() << "\n";
	for (int i = 0; i < E.size(); ++i) {
		cout << E[i] << (i == E.size() - 1 ? "\n" : " ");
	}
	return 0;
}
