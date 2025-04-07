#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	partial_sum(A.begin(), A.end(), A.begin());
	int L{}, Q{};
	cin >> L >> Q;
	while (Q--) {
		int x{};
		cin >> x;
		int ans = min(max(A[x - 1] + A[x] - L, 0), 2 * max(A[N] - L, 0));
		cout << ans / 2 << "." << (ans % 2 ? 5 : 0) << "0\n";
	}
	return 0;
}
