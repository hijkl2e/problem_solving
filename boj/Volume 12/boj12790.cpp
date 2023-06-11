#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		vector<int> A(4);
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 4; ++j) {
				int x{};
				cin >> x;
				A[j] += x;
			}
		}
		int ans = max(A[0], 1) + 5 * max(A[1], 1) + 2 * (max(A[2], 0) + A[3]);
		cout << ans << "\n";
	}
	return 0;
}
