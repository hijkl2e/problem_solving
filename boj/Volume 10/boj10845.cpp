#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	queue<int> q;
	int N{};
	cin >> N;
	while (N--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push") {
			int x{};
			cin >> x;
			q.push(x);
			continue;
		}
		int ans{};
		if (cmd == "pop") {
			if (q.size()) {
				ans = q.front();
				q.pop();
			} else {
				ans = -1;
			}
		} else if (cmd == "size") {
			ans = q.size();
		} else if (cmd == "empty") {
			ans = q.empty();
		} else if (cmd == "front") {
			ans = q.size() ? q.front() : -1;
		} else {
			ans = q.size() ? q.back() : -1;
		}
		cout << ans << "\n";
	}
	return 0;
}
