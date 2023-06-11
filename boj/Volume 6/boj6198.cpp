#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	stack<int> st;
	ll ans{};
	for (int i = 0; i < N; ++i) {
		while (st.size() && A[st.top()] <= A[i]) {
			ans += i - st.top() - 1;
			st.pop();
		}
		st.push(i);
	}
	while (st.size()) {
		ans += N - st.top() - 1;
		st.pop();
	}
	cout << ans << "\n";
	return 0;
}
