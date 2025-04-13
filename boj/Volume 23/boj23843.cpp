#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(16);
	while (N--) {
		int x{}, y{};
		cin >> x;
		while (x) {
			x /= 2;
			++y;
		}
		++A[y - 1];
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	while (M--) {
		pq.push(0);
	}
	for (int i = 15; i >= 0; --i) {
		while (A[i]--) {
			int x = pq.top(); pq.pop();
			pq.push(x + (1 << i));
		}
	}
	int ans{};
	while (pq.size()) {
		ans = max(ans, pq.top());
		pq.pop();
	}
	cout << ans << "\n";
	return 0;
}
