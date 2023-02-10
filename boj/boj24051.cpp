#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int ans = -1;
	for (int i = 1; i < N; ++i) {
		int j = i;
		int val = A[i];
		while (j && val < A[j - 1]) {
			A[j] = A[j - 1];
			if (--K == 0) {
				ans = A[j];
				i = N;
				break;
			}
			--j;
		}
		if (i != j) {
			A[j] = val;
			if (--K == 0) {
				ans = A[j];
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
