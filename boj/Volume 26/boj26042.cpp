#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	deque<int> dq;
	int cnt{}, last{};
	while (N--) {
		int q{}, x{};
		cin >> q;
		if (q == 1) {
			cin >> x;
			dq.push_back(x);
			if (cnt < dq.size()) {
				cnt = dq.size();
				last = x;
			} else if (cnt == dq.size()) {
				last = min(last, x);
			}
		} else {
			dq.pop_front();
		}
	}
	cout << cnt << " " << last << "\n";
	return 0;
}
