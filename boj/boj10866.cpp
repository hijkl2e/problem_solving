#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	deque<int> dq;
	int N{};
	cin >> N;
	while (N--) {
		string cmd;
		cin >> cmd;
		if (cmd.substr(0, 4) == "push") {
			int x{};
			cin >> x;
			if (cmd == "push_front") {
				dq.push_front(x);
			} else {
				dq.push_back(x);
			}
			continue;
		}
		int ans{};
		if (cmd.substr(0, 3) == "pop") {
			if (dq.size()) {
				if (cmd == "pop_front") {
					ans = dq.front();
					dq.pop_front();
				} else {
					ans = dq.back();
					dq.pop_back();
				}
			} else {
				ans = -1;
			}
		} else if (cmd == "size") {
			ans = dq.size();
		} else if (cmd == "empty") {
			ans = dq.empty();
		} else if (cmd == "front") {
			ans = dq.size() ? dq.front() : -1;
		} else {
			ans = dq.size() ? dq.back() : -1;
		}
		cout << ans << "\n";
	}
	return 0;
}
