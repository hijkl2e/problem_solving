#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		deque<char> dq;
		while (N--) {
			char c{};
			cin >> c;
			if (dq.empty() || c <= dq.front()) {
				dq.push_front(c);
			} else {
				dq.push_back(c);
			}
		}
		for (char c : dq) {
			cout << c;
		}
		cout << "\n";
	}
	return 0;
}
