#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	priority_queue<int> pq;
	ll ans{};
	for (int i = 0; i < N; ++i) {
		int x = A[i] - i;
		pq.push(x);
		if (pq.top() > x) {
			ans += pq.top() - x;
			pq.pop();
			pq.push(x);
		}
	}
	cout << ans << "\n";
	return 0;
}
