#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{};
	cin >> M;
	vector<int> A(M);
	for (int i = 0; i < M; ++i) {
		cin >> A[i];
	}
	int ans{};
	for (int k = 0; k < 2; ++k) {
		int cnt = 1;
		for (int i = 1; i < M; ++i) {
			if (A[i - 1] < A[i]) {
				++cnt;
			} else if (A[i - 1] > A[i]) {
				ans = max(ans, cnt);
				cnt = 1;
			}
		}
		ans = max(ans, cnt);
		reverse(A.begin(), A.end());
	}
	cout << ans << "\n";
	return 0;
}
