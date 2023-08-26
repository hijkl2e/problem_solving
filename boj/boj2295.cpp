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
	sort(A.begin(), A.end());
	vector<int> B(N * N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			B[i * N + j] = A[i] + A[j];
		}
	}
	sort(B.begin(), B.end());
	int ans{};
	for (int i = N - 1; i >= 0; --i) {
		for (int j = i - 1; j >= 0; --j) {
			if (binary_search(B.begin(), B.end(), A[i] - A[j])) {
				ans = A[i];
				i = -1;
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
