#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(4);
	vector<int> B(4);
	while (cin >> A[0], A[0]) {
		for (int i = 1; i < 4; ++i) {
			cin >> A[i];
		}
		int ans{};
		while (A[0] != A[1] || A[1] != A[2] || A[2] != A[3]) {
			for (int i = 0; i < 4; ++i) {
				B[i] = abs(A[i] - A[(i + 1) % 4]);
			}
			swap(A, B);
			++ans;
		}
		cout << ans << "\n";
	}
	return 0;
}
