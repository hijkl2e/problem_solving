#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		for (int k = 0; k < 2; ++k) {
			ans = max(ans, k + 1);
			for (int j = 1; i + j + k < N && i - j >= 0; ++j) {
				if (A[i - j] < A[i - j + 1] && A[i - j] == A[i + j + k]) {
					ans = max(ans, 2 * j + k + 1);
				} else {
					break;
				}
			}
			if (i == N - 1 || A[i] != A[i + 1]) {
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
