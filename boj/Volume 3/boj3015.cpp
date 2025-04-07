#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

ll solve(vector<int> &A, bool f) {
	ll ret{};
	stack<ii> st;
	for (int i = 0; i < A.size(); ++i) {
		while (st.size() && st.top().first < A[i]) {
			ret += st.top().second;
			st.pop();
		}
		if (st.size() && st.top().first == A[i]) {
			int x = st.top().second++;
			if (f) {
				ret += x;
			}
		} else {
			st.push({A[i], 1});
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	ll ans = solve(A, true);
	reverse(A.begin(), A.end());
	ans += solve(A, false);
	cout << ans << "\n";
	return 0;
}
