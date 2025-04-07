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
		int ans = max(A[1] - A[0], A[N - 1] - A[N - 2]);
		for (int i = 0; i < N - 2; ++i) {
			ans = max(ans, A[i + 2] - A[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}
