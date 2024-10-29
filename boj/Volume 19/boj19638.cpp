#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, H{}, T{};
	cin >> N >> H >> T;
	priority_queue<int> pq;
	while (N--) {
		int x{};
		cin >> x;
		pq.push(x);
	}
	int cnt{};
	while (cnt < T && pq.top() >= H && pq.top() > 1) {
		int x = pq.top() / 2;
		pq.pop();
		pq.push(x);
		++cnt;
	}
	if (pq.top() < H) {
		cout << "YES\n" << cnt << "\n";
	} else {
		cout << "NO\n" << pq.top() << "\n";
	}
	return 0;
}
