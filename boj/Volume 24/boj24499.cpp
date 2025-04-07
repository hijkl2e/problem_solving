#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(2 * N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	copy(A.begin(), A.begin() + N, A.begin() + N);
	partial_sum(A.begin(), A.end(), A.begin());
	int ans{};
	for (int i = K; i < 2 * N; ++i) {
		ans = max(ans, A[i] - A[i - K]);
	}
	cout << ans << "\n";
	return 0;
}
