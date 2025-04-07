#include <bits/stdc++.h>

using namespace std;

int N, ans;
vector<int> A, B;

void solve(int n) {
	if (n == N) {
		int cnt{};
		for (int i = 0; i < N; ++i) {
			if (A[i] <= 0) {
				++cnt;
			}
		}
		ans = max(ans, cnt);
		return;
	} else if (A[n] <= 0) {
		solve(n + 1);
		return;
	}
	for (int i = 0; i < N; ++i) {
		if (i == n || A[i] <= 0) {
			continue;
		}
		A[i] -= B[n];
		A[n] -= B[i];
		solve(n + 1);
		A[i] += B[n];
		A[n] += B[i];
	}
	solve(N);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	A.resize(N);
	B.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i] >> B[i];
	}
	solve(0);
	cout << ans << "\n";
	return 0;
}
