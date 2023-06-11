#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	priority_queue<int> pq;
	while (--N) {
		int x{};
		cin >> x;
		pq.push(x);
	}
	int ans{};
	while (pq.size() && pq.top() >= M) {
		int x = pq.top(); pq.pop();
		pq.push(x - 1);
		++M, ++ans;
	}
	cout << ans << "\n";
	return 0;
}
