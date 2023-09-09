#include <bits/stdc++.h>

using namespace std;

int N, K, ans;
vector<int> A;

void solve(int x) {
	if (x > N) {
		return;
	}
	ans = max(ans, x);
	for (int i = 0; i < K; ++i) {
		solve(10 * x + A[i]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> K;
	A.resize(K);
	for (int i = 0; i < K; ++i) {
		cin >> A[i];
	}
	solve(0);
	cout << ans << "\n";
	return 0;
}
