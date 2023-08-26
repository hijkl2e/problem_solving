#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	stack<ii> st;
	int ans{};
	while (N--) {
		int q{};
		cin >> q;
		if (q) {
			int x{}, y{};
			cin >> x >> y;
			st.push({x, y});
		}
		if (st.size() && --st.top().second == 0) {
			ans += st.top().first;
			st.pop();
		}
	}
	cout << ans << "\n";
	return 0;
}
