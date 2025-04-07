#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	partial_sum(A.begin(), A.end(), A.begin());
	int ans{};
	while (M--) {
		int p{}, r{}, c{};
		cin >> p >> r >> c;
		int t = A[r - 1] - A[p - 1] + c + (A[N] + A[p - 1] - c % A[N]) % A[N] + (p < r ? 0 : A[N]);
		ans = max(ans, t);
	}
	cout << ans << "\n";
	return 0;
}
