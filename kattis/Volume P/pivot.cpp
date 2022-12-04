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
	deque<bool> B(N, true);
	int maxv = A[0];
	for (int i = 1; i < N; ++i) {
		if (A[i] < maxv) {
			B[i] = false;
		}
		maxv = max(maxv, A[i]);
	}
	int minv = A[N - 1];
	for (int i = N - 2; i >= 0; --i) {
		if (A[i] >= minv) {
			B[i] = false;
		}
		minv = min(minv, A[i]);
	}
	int ans = accumulate(B.begin(), B.end(), 0);
	cout << ans << "\n";
	return 0;
}
