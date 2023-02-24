#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	priority_queue<int> pq;
	int N{};
	cin >> N;
	while (N--) {
		int x{};
		cin >> x;
		if (x) {
			pq.push(x);
			continue;
		}
		int ans{};
		if (pq.size()) {
			ans = pq.top(); pq.pop();
		}
		cout << ans << "\n";
	}
	return 0;
}
