#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, R{}, C{};
	cin >> N >> R >> C;
	vector<ii> A(N);
	for (int i = 0; i < N; ++i) {
		int a{}, b{}, s{};
		cin >> a >> b >> s;
		A[i] = {max(a - s, 1), min(a + s, R)};
	}
	sort(A.begin(), A.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	int ans{};
	for (int i = 1, j = 0; i <= R; ++i) {
		while (pq.size() && pq.top() < i) {
			pq.pop();
		}
		while (j < N && A[j].first == i) {
			pq.push(A[j++].second);
		}
		for (int k = 0; k < C && pq.size(); ++k) {
			pq.pop();
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
