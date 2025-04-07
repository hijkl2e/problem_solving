#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> A(N + 1);
		for (int i = 1; i <= N; ++i) {
			cin >> A[i];
		}
		vector<int> ind(N + 1);
		for (int i = 1; i <= N; ++i) {
			++ind[A[i]];
		}
		queue<int> q;
		for (int i = 1; i <= N; ++i) {
			if (ind[i] == 0) {
				q.push(i);
			}
		}
		while (q.size()) {
			int x = q.front(); q.pop();
			if (--ind[A[x]] == 0) {
				q.push(A[x]);
			}
		}
		int ans = count(ind.begin() + 1, ind.end(), 0);
		cout << ans << "\n";
	}
	return 0;
}
