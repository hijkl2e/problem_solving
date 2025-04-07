#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ii> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].second >> A[i].first;
	}
	sort(A.rbegin(), A.rend());
	priority_queue<int> pq;
	int ans{};
	for (int i = N, j = 0; i > 0; --i) {
		while (j < N && A[j].first >= i) {
			pq.push(A[j++].second);
		}
		if (pq.size()) {
			ans += pq.top(); pq.pop();
		}
	}
	cout << ans << "\n";
	return 0;
}
