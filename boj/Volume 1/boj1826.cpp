#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ii> A(N + 2);
	for (int i = 1; i < N + 2; ++i) {
		cin >> A[i].first >> A[i].second;
	}
	int P = A[N + 1].second;
	A[N + 1].second = 0;
	sort(A.begin(), A.end());
	priority_queue<int> pq;
	int ans{};
	for (int i = 1; i < N + 2; ++i) {
		P -= A[i].first - A[i - 1].first;
		while (P < 0 && pq.size()) {
			P += pq.top();
			pq.pop();
			++ans;
		}
		if (P < 0) {
			ans = -1;
			break;
		}
		pq.push(A[i].second);
	}
	cout << ans << "\n";
	return 0;
}
