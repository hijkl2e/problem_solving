#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{}, K{};
		cin >> N >> M >> K;
		vector<int> A(2 * N + 1);
		for (int i = 1; i <= N; ++i) {
			cin >> A[i];
		}
		copy(A.begin() + 1, A.begin() + N + 1, A.begin() + N + 1);
		partial_sum(A.begin(), A.end(), A.begin());
		int ans{};
		for (int i = 1; i <= N; ++i) {
			if (A[i + M] - A[i] < K) {
				++ans;
			}
		}
		if (N == M) {
			ans = ans ? 1 : 0;
		}
		cout << ans << "\n";
	}
	return 0;
}
