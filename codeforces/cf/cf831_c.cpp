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
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		sort(A.begin(), A.end());
		int ans{};
		for (int i = N - 1; i > 1; --i) {
			int val = (A[i] - A[0]) + (A[i] - A[i - 1]);
			ans = max(ans, val);
		}
		for (int i = 0; i < N - 2; ++i) {
			int val = (A[N - 1] - A[i]) + (A[i + 1] - A[i]);
			ans = max(ans, val);
		}
		cout << ans << "\n";
	}
	return 0;
}
