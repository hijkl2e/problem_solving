#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<ii> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first >> A[i].second;
	}
	vector<int> B(K);
	for (int i = 0; i < K; ++i) {
		cin >> B[i];
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	priority_queue<int> pq;
	int p{};
	ll ans{};
	for (int i = 0; i < K; ++i) {
		while (p < N && A[p].first <= B[i]) {
			pq.push(A[p++].second);
		}
		if (pq.size()) {
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans << "\n";
	return 0;
}
