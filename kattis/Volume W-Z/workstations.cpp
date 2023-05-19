#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<ii> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first >> A[i].second;
	}
	sort(A.begin(), A.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	int ans{};
	for (int i = 0; i < N; ++i) {
		while (pq.size() && pq.top() + M < A[i].first) {
			pq.pop();
		}
		if (pq.size() && pq.top() <= A[i].first) {
			pq.pop();
			++ans;
		}
		pq.push(A[i].first + A[i].second);
	}
	cout << ans << "\n";
	return 0;
}
