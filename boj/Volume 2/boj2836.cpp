#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<ii> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first >> A[i].second;
	}
	sort(A.begin(), A.end());
	stack<ii> st;
	for (int i = 0; i < N; ++i) {
		if (A[i].first < A[i].second) {
			continue;
		}
		while (st.size() && A[i].second < st.top().second) {
			st.pop();
		}
		if (st.empty() || st.top().first < A[i].second) {
			st.push(A[i]);
		} else {
			st.top().first = A[i].first;
		}
	}
	ll ans = M;
	while (st.size()) {
		auto [x, y] = st.top(); st.pop();
		ans += 2 * (x - y);
	}
	cout << ans << "\n";
	return 0;
}
