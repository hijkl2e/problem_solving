#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	stack<int> st;
	int ans{};
	while (N--) {
		int x{}, y{};
		cin >> x >> y;
		while (st.size() && st.top() > y) {
			st.pop();
		}
		if (y && (st.empty() || st.top() < y)) {
			st.push(y);
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
