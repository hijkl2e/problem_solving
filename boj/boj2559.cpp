#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<int> psum(N + 1);
	partial_sum(A.begin(), A.end(), psum.begin());
	int ans = -1e9;
	for (int i = K; i <= N; ++i) {
		ans = max(ans, psum[i] - psum[i - K]);
	}
	cout << ans << "\n";
	return 0;
}
