#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(45);
	for (int i = 1; i < 45; ++i) {
		A[i] = i * (i + 1) / 2;
	}
	deque<bool> B(1001);
	for (int i = 1; i < 45; ++i) {
		for (int j = i; j < 45; ++j) {
			for (int k = j; k < 45; ++k) {
				int sum = A[i] + A[j] + A[k];
				if (sum < B.size()) {
					B[sum] = true;
				}
			}
		}
	}
	int T{};
	cin >> T;
	while (T--) {
		int x{};
		cin >> x;
		cout << B[x] << "\n";
	}
	return 0;
}
