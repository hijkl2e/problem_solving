#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	stack<int> st;
	while (N--) {
		int q{};
		cin >> q;
		if (q == 1) {
			int x{};
			cin >> x;
			st.push(x);
			continue;
		}
		int ans = -1;
		if (q == 2) {
			if (st.size()) {
				ans = st.top(); st.pop();
			}
		} else if (q == 3) {
			ans = st.size();
		} else if (q == 4) {
			ans = st.empty();
		} else {
			if (st.size()) {
				ans = st.top();
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
