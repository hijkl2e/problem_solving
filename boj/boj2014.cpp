#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = (1LL << 31) - 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N; ++i) {
		pq.push(A[i]);
	}
	while (--M) {
		int x = pq.top(); pq.pop();
		for (int i = 0; i < N; ++i) {
			ll y = 1LL * x * A[i];
			if (y > INF) {
				break;
			}
			pq.push(y);
			if (x % A[i] == 0) {
				break;
			}
		}
	}
	cout << pq.top() << "\n";
	return 0;
}
