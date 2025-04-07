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
	vector<int> B(10);
	int ans{}, cnt{};
	for (int i = 0, j = 0; i < N; ++i) {
		while (j < N && (cnt < 2 || B[A[j]])) {
			if (B[A[j++]]++ == 0) {
				++cnt;
			}
		}
		ans = max(ans, j - i);
		if (--B[A[i]] == 0) {
			--cnt;
		}
	}
	cout << ans << "\n";
	return 0;
}
