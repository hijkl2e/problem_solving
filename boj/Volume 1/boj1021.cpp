#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	deque<int> dq;
	for (int i = 1; i <= N; ++i) {
		dq.push_back(i);
	}
	int ans{};
	while (M--) {
		int x{}, cnt{};
		cin >> x;
		while (dq.front() != x) {
			dq.push_back(dq.front());
			dq.pop_front();
			++cnt;
		}
		ans += min<int>(cnt, dq.size() - cnt);
		dq.pop_front();
	}
	cout << ans << "\n";
	return 0;
}
