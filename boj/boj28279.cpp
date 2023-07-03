#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	deque<int> dq;
	while (N--) {
		int q{};
		cin >> q;
		if (q == 1 || q == 2) {
			int x{};
			cin >> x;
			if (q == 1) {
				dq.push_front(x);
			} else {
				dq.push_back(x);
			}
			continue;
		}
		int ans = -1;
		if (q == 3) {
			if (dq.size()) {
				ans = dq.front(); dq.pop_front();
			}
		} else if (q == 4) {
			if (dq.size()) {
				ans = dq.back(); dq.pop_back();
			}
		} else if (q == 5) {
			ans = dq.size();
		} else if (q == 6) {
			ans = dq.empty();
		} else if (q == 7) {
			if (dq.size()) {
				ans = dq.front();
			}
		} else {
			if (dq.size()) {
				ans = dq.back();
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
