#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{}, B{};
	cin >> N >> K >> B;
	vector<int> A(N + 1);
	while (B--) {
		int x{};
		cin >> x;
		A[x] = 1;
	}
	partial_sum(A.begin(), A.end(), A.begin());
	int ans = 1e9;
	for (int i = K; i <= N; ++i) {
		ans = min(ans, A[i] - A[i - K]);
	}
	cout << ans << "\n";
	return 0;
}
