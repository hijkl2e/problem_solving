#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int Q{};
	cin >> Q;
	deque<char> dq;
	int b{}, w{}, d{};
	while (Q--) {
		string cmd;
		char c{};
		cin >> cmd;
		if (cmd != "pop") {
			cin >> c;
		}
		if (cmd == "push") {
			dq.push_back(c);
			if (c == 'b') {
				++b;
			} else {
				++w;
			}
		} else if (cmd == "pop") {
			if (dq.size()) {
				if (dq.front() == 'b') {
					--b;
				} else {
					--w;
				}
				dq.pop_front();
			}
		} else if (cmd == "rotate") {
			d = (d + (c == 'r' ? 1 : 3)) % 4;
		} else {
			cout << (c == 'b' ? b : w) << "\n";
		}
		while (d == 1 && dq.size() && dq.front() == 'b') {
			dq.pop_front();
			--b;
		}
		while (d == 3 && dq.size() && dq.back() == 'b') {
			dq.pop_back();
			--b;
		}
	}
	return 0;
}
