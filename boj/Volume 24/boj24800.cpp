#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int S{}, N{};
	cin >> S >> N;
	deque<int> dq;
	for (int i = 0; i < N; ++i) {
		dq.push_back(2 * (N + i));
	}
	while (dq.size() > 1) {
		for (int i = 0; i < S - 1; ++i) {
			dq.push_back(dq.front());
			dq.pop_front();
		}
		int x = dq.front(); dq.pop_front();
		if (x >= 2 * N) {
			x -= 2 * N;
			dq.push_front(x);
			dq.push_front(x);
		} else if (x % 2 == 0) {
			dq.push_back(x + 1);
		}
	}
	int ans = (dq.front() % (2 * N)) / 2 + 1;
	cout << ans << "\n";
	return 0;
}
