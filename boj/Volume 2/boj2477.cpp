#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{};
	cin >> K;
	vector<int> A(6);
	vector<int> B(6);
	for (int i = 0; i < 6; ++i) {
		cin >> A[i] >> B[i];
	}
	while (A[2] != A[4] || A[3] != A[5]) {
		rotate(A.begin(), A.begin() + 1, A.end());
		rotate(B.begin(), B.begin() + 1, B.end());
	}
	int ans = K * (B[0] * B[1] - B[3] * B[4]);
	cout << ans << "\n";
	return 0;
}
