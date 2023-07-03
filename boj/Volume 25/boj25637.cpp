#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int ans = 1e9;
	queue<int> q1, q2;
	for (int k = 0; k < N; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 1; j < A[i]; ++j) {
				q1.push(i);
			}
			if (A[i] == 0) {
				q2.push(i);
			}
		}
		int cnt{};
		while (q1.size()) {
			int x = q1.front(); q1.pop();
			int y = q2.front(); q2.pop();
			cnt += abs(x - y);
		}
		ans = min(ans, cnt);
		rotate(A.begin(), A.begin() + 1, A.end());
	}
	cout << ans << "\n";
	return 0;
}
