#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<ii> A(K);
	for (auto &[u, v] : A) {
		cin >> v >> u;
	}
	sort(A.begin(), A.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	int ans{};
	ll sum{};
	for (auto &[u, v] : A) {
		ans = max(ans, u);
		if (pq.size() < N) {
			pq.push(v);
			sum += v;
		} else if (pq.top() < v) {
			sum -= pq.top();
			pq.pop();
			pq.push(v);
			sum += v;
		}
		if (sum >= M && pq.size() == N) {
			break;
		}
	}
	cout << (sum >= M ? ans : -1) << "\n";
	return 0;
}
