#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	queue<int> q;
	int ans{};
	while (N--) {
		int x{};
		cin >> x;
		while (q.size() && q.front() + 1000 <= x) {
			q.pop();
		}
		q.push(x);
		ans = max<int>(ans, q.size());
	}
	ans = (ans - 1) / K + 1;
	cout << ans << "\n";
	return 0;
}
