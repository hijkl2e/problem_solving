#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(10);
	vector<int> B(10);
	for (int i = 0; i < 10; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < 10; ++i) {
		cin >> B[i];
	}
	sort(A.rbegin(), A.rend());
	sort(B.rbegin(), B.rend());
	cout << A[0] + A[1] + A[2] << " " << B[0] + B[1] + B[2] << "\n";
	return 0;
}
