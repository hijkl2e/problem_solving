#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	queue<int> q;
	for (int i = 1; i <= N; ++i) {
		q.push(i);
	}
	int ans{};
	while (true) {
		if (q.size() < K) {
			ans = q.front();
			break;
		}
		q.push(q.front());
		q.pop();
		for (int i = 0; i < K - 1; ++i) {
			q.pop();
		}
	}
	cout << ans << "\n";
	return 0;
}
