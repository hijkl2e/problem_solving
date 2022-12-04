#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int P{}, D{};
	cin >> P >> D;
	vector<int> A(D + 1);
	vector<int> B(D + 1);
	while (P--) {
		int d{}, a{}, b{};
		cin >> d >> a >> b;
		A[d] += a;
		B[d] += b;
	}
	int V = accumulate(A.begin(), A.end(), 0) + accumulate(B.begin(), B.end(), 0);
	for (int i = 1; i <= D; ++i) {
		cout << (A[i] > B[i] ? 'A' : 'B') << " ";
		if (A[i] > B[i]) {
			A[i] -= (A[i] + B[i]) / 2 + 1;
		} else {
			B[i] -= (A[i] + B[i]) / 2 + 1;
		}
		cout << A[i] << " " << B[i] << "\n";
	}
	double ans = abs(accumulate(A.begin(), A.end(), 0) - accumulate(B.begin(), B.end(), 0)) * 1.0 / V;
	cout << fixed << setprecision(10) << ans << "\n";
	return 0;
}
