#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

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
	stack<ii> st;
	for (int i = 0; i < N; ++i) {
		if (st.empty() || st.top().second < A[i].first) {
			st.push(A[i]);
		} else {
			int &val = st.top().second;
			val = max(val, A[i].second);
		}
	}
	int ans{};
	while (st.size()) {
		auto [x, y] = st.top(); st.pop();
		ans += y - x;
	}
	cout << ans << "\n";
	return 0;
}
