#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{}, N{};
	cin >> K >> N;
	vector<vector<int>> A(9);
	for (int i = 1; i < A.size(); ++i) {
		A[i].push_back(K);
		K = 10 * K + K % 10;
	}
	for (int i = 2; i < A.size(); ++i) {
		for (int j = 1; j <= i - j; ++j) {
			for (int x : A[j]) {
				for (int y : A[i - j]) {
					A[i].push_back(x + y);
					A[i].push_back(x - y);
					A[i].push_back(y - x);
					A[i].push_back(x * y);
					if (y) {
						A[i].push_back(x / y);
					}
					if (x) {
						A[i].push_back(y / x);
					}
				}
			}
		}
		sort(A[i].begin(), A[i].end());
		A[i].resize(unique(A[i].begin(), A[i].end()) - A[i].begin());
	}
	while (N--) {
		int x{};
		cin >> x;
		int ans = -1;
		for (int i = 1; i < A.size(); ++i) {
			if (binary_search(A[i].begin(), A[i].end(), x)) {
				ans = i;
				break;
			}
		}
		if (ans == -1) {
			cout << "NO\n";
		} else {
			cout << ans << "\n";
		}
	}
	return 0;
}
