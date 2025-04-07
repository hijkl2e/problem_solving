#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<stack<int>> st(7);
	int ans{};
	while (N--) {
		int x{}, y{};
		cin >> x >> y;
		while (st[x].size() && st[x].top() > y) {
			st[x].pop();
			++ans;
		}
		if (st[x].empty() || st[x].top() < y) {
			st[x].push(y);
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
