#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int K{}, p{}, q{};
		char c{};
		cin >> K >> p >> c >> q;
		stack<bool> st;
		while (p + q > 2) {
			if (p > q) {
				p -= q;
				st.push(true);
			} else {
				q -= p;
				st.push(false);
			}
		}
		int ans = 1;
		while (st.size()) {
			ans = 2 * ans + st.top();
			st.pop();
		}
		cout << K << " " << ans << "\n";
	}
	return 0;
}
