#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	priority_queue<int> pq;
	ll sum{}, ans{};
	for (int i = 0; i < N; ++i) {
		sum += A[i];
		pq.push(A[i]);
		if (sum >= M) {
			sum -= 2 * pq.top();
			pq.pop();
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
