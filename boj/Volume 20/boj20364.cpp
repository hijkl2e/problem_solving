#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Q{};
	cin >> N >> Q;
	vector<int> A(Q);
	for (int i = 0; i < Q; ++i) {
		cin >> A[i];
	}
	deque<bool> B(1 << 20);
	for (int i = 0; i < Q; ++i) {
		int ans{};
		for (int j = 19; j >= 0; --j) {
			if (B[A[i] >> j]) {
				ans = A[i] >> j;
				break;
			}
		}
		if (ans == 0) {
			B[A[i]] = true;
		}
		cout << ans << "\n";
	}
	return 0;
}
