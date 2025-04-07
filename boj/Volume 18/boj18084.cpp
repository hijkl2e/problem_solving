#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(5);
	for (int i = 0; i < 5; ++i) {
		double x{};
		cin >> x;
		A[i] = 100 * x + EPS;
	}
	sort(A.begin(), A.begin() + 4);
	if (A[0] + A[1] + A[2] > 3 * A[4]) {
		cout << "impossible\n";
	} else if (A[1] + A[2] + A[3] <= 3 * A[4]) {
		cout << "infinite\n";
	} else {
		int ans = 3 * A[4] - A[2] - A[1];
		cout << ans / 100 << "." << setw(2) << setfill('0') << ans % 100 << "\n";
	}
	return 0;
}
