#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 998244353;

int N;
vector<int> A, B, C;
ll ans;

void solve(int s1, int e1, int s2, int e2) {
	if (s1 == e1) {
		return;
	}
	if (A[s1] == B[e2 - 1]) {
		ans = 2 * ans % MOD;
		solve(s1 + 1, e1, s2, e2 - 1);
		return;
	}
	int x = C[A[s1]];
	int len = x - s2 + 1;
	if (0 < len && len <= e2 - s2 && A[s1 + len] == B[e2 - 1]) {
		solve(s1 + 1, s1 + len, s2, s2 + len - 1);
		solve(s1 + len + 1, e1, s2 + len, e2 - 1);
	} else {
		ans = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	A.resize(N);
	B.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	ans = A[0] == B[N - 1];
	C.resize(N + 1);
	for (int i = 0; i < N; ++i) {
		C[B[i]] = i;
	}
	solve(1, N, 0, N - 1);
	cout << ans << "\n";
	return 0;
}
