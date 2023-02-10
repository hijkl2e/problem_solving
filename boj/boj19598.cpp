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
		cin >> A[i].first >> A[i].second;
	}
	sort(A.begin(), A.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	for (auto &p : A) {
		if (pq.size() && pq.top() <= p.first) {
			pq.pop();
		}
		pq.push(p.second);
	}
	cout << pq.size() << "\n";
	return 0;
}
