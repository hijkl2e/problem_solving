#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{}, N{};
	cin >> K >> N;
	vector<ii> A(N + K - 1);
	for (int i = 0; i < A.size(); ++i) {
		cin >> A[i].first >> A[i].second;
	}
	int kap = A[0].second;
	sort(A.begin(), A.end());
	priority_queue<int> pq;
	for (int i = 0; i < K - 1; ++i) {
		pq.push(A[i].second);
	}
	int ans = -1;
	for (int i = K - 1; i < A.size(); ++i) {
		pq.push(A[i].second);
		if (pq.top() == kap) {
			ans = A[i].first;
			break;
		}
		pq.pop();
	}
	if (ans == -1) {
		cout << "unknown\n";
	} else {
		cout << ans << "\n";
	}
	return 0;
}
