#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> sz(12);
	sz[11] = 1;
	for (int i = 10; i >= 0; --i) {
		cin >> sz[i];
		sz[i] *= sz[i + 1];
	}
	vector<int> A(sz[0]);
	for (int i = 0; i < A.size(); ++i) {
		cin >> A[i];
	}
	vector<int> D(A.size());
	queue<int> q;
	for (int i = 0; i < A.size(); ++i) {
		if (A[i] == 1) {
			q.push(i);
		}
	}
	vector<int> B(11);
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int i = 0; i < 11; ++i) {
			B[i] = x % sz[i] / sz[i + 1];
		}
		for (int i = 0; i < 11; ++i) {
			if (B[i]) {
				int y = x - sz[i + 1];
				if (A[y] == 0) {
					A[y] = 1;
					D[y] = D[x] + 1;
					q.push(y);
				}
			}
			if (B[i] + 1 < sz[i] / sz[i + 1]) {
				int y = x + sz[i + 1];
				if (A[y] == 0) {
					A[y] = 1;
					D[y] = D[x] + 1;
					q.push(y);
				}
			}
		}
	}
	int ans = *max_element(D.begin(), D.end());
	if (count(A.begin(), A.end(), 0)) {
		ans = -1;
	}
	cout << ans << "\n";
	return 0;
}
