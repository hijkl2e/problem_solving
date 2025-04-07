#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int x{};
		cin >> x;
		vector<int> A{x};
		while ((x & -x) != x) {
			x -= x & -x;
			A.push_back(x);
		}
		while (x > 1) {
			x /= 2;
			A.push_back(x);
		}
		cout << A.size() << "\n";
		for (int i = 0; i < A.size(); ++i) {
			cout << A[i] << (i == A.size() - 1 ? "\n" : " ");
		}
	}
	return 0;
}
