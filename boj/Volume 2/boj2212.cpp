#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	K = min(K, N) - 1;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	vector<int> B(N - 1);
	for (int i = 0; i < N - 1; ++i) {
		B[i] = A[i + 1] - A[i];
	}
	sort(B.begin(), B.end());
	int ans = A[N - 1] - A[0] - accumulate(B.rbegin(), B.rbegin() + K, 0);
	cout << ans << "\n";
	return 0;
}
