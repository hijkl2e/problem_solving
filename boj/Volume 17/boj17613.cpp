#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int x{}, y{};
		cin >> x >> y;
		vector<int> A;
		int z = x;
		for (int i = 29; i > 0; --i) {
			while (z >= (1 << i) - 1) {
				z -= (1 << i) - 1;
				A.push_back(i);
			}
		}
		int ans = accumulate(A.begin(), A.end(), 0);
		while (x <= y) {
			if (A.size() > 1 && A[A.size() - 2] == A[A.size() - 1]) {
				A.pop_back();
				++A.back(), ++x;
			} else if (x + (1 << A.back()) - 1 <= y) {
				ans = max(ans, accumulate(A.begin(), A.end(), 0)
							+ A.back() * (A.back() - 1) / 2 + 1);
				x += (1 << A.back()++);
			} else {
				break;
			}
		}
		while (x <= y) {
			ans = max(ans, accumulate(A.begin(), A.end(), 0));
			if (x + (1 << A.back()) - 1 <= y) {
				ans = max(ans, accumulate(A.begin(), A.end(), 0)
							+ A.back() * (A.back() - 1) / 2 + 1);
				x += (1 << A.back()++);
			} else {
				A.push_back(1), ++x;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
