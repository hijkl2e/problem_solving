#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N, N) {
		vector<ll> H(N);
		for (int i = 0; i < N; ++i) {
			cin >> H[i];
		}
		vector<int> L(N);
		vector<int> R(N, N);
		stack<int> st;
		for (int i = 0; i < N; ++i) {
			while (st.size() && H[st.top()] > H[i]) {
				int x = st.top(); st.pop();
				R[x] = i;
			}
			st.push(i);
		}
		while (st.size()) {
			st.pop();
		}
		for (int i = N - 1; i >= 0; --i) {
			while (st.size() && H[st.top()] > H[i]) {
				int x = st.top(); st.pop();
				L[x] = i + 1;
			}
			st.push(i);
		}
		ll ans{};
		for (int i = 0; i < N; ++i) {
			ans = max(ans, (R[i] - L[i]) * H[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}
