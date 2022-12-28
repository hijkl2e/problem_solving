#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	vector<vector<int>> C(N);
	for (int i = 0; i < N; ++i) {
		C[A[i] - 1].push_back(B[i]);
	}
	for (int i = 0; i < N; ++i) {
		sort(C[i].begin(), C[i].end());
	}
	priority_queue<ii, vector<ii>, greater<ii>> pq1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < C[i].size(); ++j) {
			pq1.push({j, C[i][j]});
		}
	}
	priority_queue<int> pq2;
	ll ans{};
	for (int i = 0; i < N; ++i) {
		while (pq1.size() && pq1.top().first == i) {
			auto [x, y] = pq1.top(); pq1.pop();
			pq2.push(y);
			ans += y;
		}
		while (pq2.size() > K) {
			ans -= pq2.top();
			pq2.pop();
		}
		cout << (pq2.size() == K ? ans : -1) << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
