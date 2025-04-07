#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		queue<int> q;
		for (int i = 0; i < N; ++i) {
			q.push(A[i]);
		}
		sort(A.begin(), A.end());
		int ans{};
		for (int i = 1;; ++i) {
			while (q.front() < A.back()) {
				q.push(q.front());
				q.pop();
				M = (M + q.size() - 1) % q.size();
			}
			if (M--) {
				q.pop();
				A.pop_back();
			} else {
				ans = i;
				break;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
