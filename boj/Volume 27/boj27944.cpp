#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll N, ans;
vector<ll> A;

void solve(int n, ll g) {
	if (g == 1 || g < ans) {
		return;
	} else if (n == N) {
		ans = max(ans, g);
		return;
	}
	solve(n + 1, gcd(g, A[n]));
	solve(n + 1, gcd(g, A[n] + 1));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	ans = 1;
	solve(1, A[0]);
	solve(1, A[0] + 1);
	cout << ans << "\n";
	return 0;
}
