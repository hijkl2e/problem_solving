#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	deque<int> dq1, dq2;
	while (N--) {
		string cmd;
		int x{};
		cin >> cmd >> x;
		if (cmd == "get") {
			int ans = x < dq1.size() ? dq1[x] : dq2[x - dq1.size()];
			cout << ans << "\n";
			continue;
		}
		if (cmd == "push_back") {
			dq2.push_back(x);
		} else if (cmd == "push_front") {
			dq1.push_front(x);
		} else {
			dq1.push_back(x);
		}
		if (dq1.size() > dq2.size() + 1) {
			dq2.push_front(dq1.back());
			dq1.pop_back();
		} else if (dq1.size() < dq2.size()) {
			dq1.push_back(dq2.front());
			dq2.pop_front();
		}
	}
	return 0;
}
