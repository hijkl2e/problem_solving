#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans{};
	while (N--) {
		vector<int> A(3);
		for (int i = 0; i < 3; ++i) {
			cin >> A[i];
		}
		sort(A.begin(), A.end());
		int x{};
		if (A[0] == A[2]) {
			x = 10000 + A[0] * 1000;
		} else if (A[0] == A[1] || A[1] == A[2]) {
			x = 1000 + A[1] * 100;
		} else {
			x = A[2] * 100;
		}
		ans = max(ans, x);
	}
	cout << ans << "\n";
	return 0;
}
