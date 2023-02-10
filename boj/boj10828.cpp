#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	stack<int> st;
	int N{};
	cin >> N;
	while (N--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push") {
			int x{};
			cin >> x;
			st.push(x);
			continue;
		}
		int ans{};
		if (cmd == "pop") {
			if (st.size()) {
				ans = st.top();
				st.pop();
			} else {
				ans = -1;
			}
		} else if (cmd == "size") {
			ans = st.size();
		} else if (cmd == "empty") {
			ans = st.empty();
		} else {
			ans = st.size() ? st.top() : -1;
		}
		cout << ans << "\n";
	}
	return 0;
}
