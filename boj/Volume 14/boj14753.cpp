#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A, B;
	while (N--) {
		int x{};
		cin >> x;
		if (x > 0) {
			A.push_back(x);
		} else if (x < 0) {
			B.push_back(x);
		}
	}
	sort(A.rbegin(), A.rend());
	sort(B.begin(), B.end());
	int ans{};
	if (A.size() > 1) {
		ans = max(ans, A[0] * A[1]);
		if (A.size() > 2) {
			ans = max(ans, A[0] * A[1] * A[2]);
		}
	}
	if (B.size() > 1) {
		ans = max(ans, B[0] * B[1]);
		if (A.size()) {
			ans = max(ans, B[0] * B[1] * A[0]);
		}
	}
	cout << ans << "\n";
	return 0;
}
