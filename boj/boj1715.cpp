#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;
	while (N--) {
		int x{};
		cin >> x;
		pq.push(x);
	}
	int ans{};
	while (pq.size() > 1) {
		int x = pq.top(); pq.pop();
		int y = pq.top(); pq.pop();
		ans += x + y;
		pq.push(x + y);
	}
	cout << ans << "\n";
	return 0;
}
