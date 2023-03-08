#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	deque<char> dq;
	stack<bool> st;
	while (N--) {
		int q{};
		char c{};
		cin >> q;
		if (q == 3) {
			if (st.empty()) {
				continue;
			} else if (st.top()) {
				dq.pop_back();
			} else {
				dq.pop_front();
			}
			st.pop();
			continue;
		}
		cin >> c;
		if (q == 1) {
			dq.push_back(c);
			st.push(true);
		} else {
			dq.push_front(c);
			st.push(false);
		}
	}
	if (dq.empty()) {
		cout << "0\n";
	} else {
		for (char c : dq) {
			cout << c;
		}
		cout << "\n";
	}
	return 0;
}
