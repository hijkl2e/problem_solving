#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		vector<vector<int>> A(N + 1);
		while (M--) {
			int a{}, b{};
			cin >> a >> b;
			A[a].push_back(b);
		}
		priority_queue<int, vector<int>, greater<int>> pq;
		int ans{};
		for (int i = 1; i <= N; ++i) {
			while (pq.size() && pq.top() < i) {
				pq.pop();
			}
			for (int x : A[i]) {
				pq.push(x);
			}
			if (pq.size()) {
				++ans, pq.pop();
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
