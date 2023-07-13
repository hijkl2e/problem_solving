#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int N, K;
vector<int> A;

int solve() {
	int ret = -INF;
	int maxv = A[0];
	for (int i = 1; i < N; ++i) {
		ret = max(ret, maxv - A[i] - i * K);
		maxv = max(maxv, A[i] + i * K);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> K;
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int ans = solve();
	reverse(A.begin(), A.end());
	ans = max(ans, solve());
	cout << ans << "\n";
	return 0;
}
