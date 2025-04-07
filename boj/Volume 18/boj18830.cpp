#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<int> sz(12);
vector<vector<ll>> A(12);
vector<int> B(11);
vector<int> C(11);

ll solve(int n, int x, int c) {
	if (n == 11) {
		return c * A[0][x];
	}
	ll ret{};
	if (B[n]) {
		ret += solve(n + 1, x + sz[n + 1] * (B[n] - 1), c == 1 ? -1 : 1);
	}
	ret += solve(n + 1, x + sz[n + 1] * C[n], c);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 0; i < 11; ++i) {
		cin >> sz[i];
	}
	sz[11] = 1;
	for (int i = 10; i >= 0; --i) {
		sz[i] *= sz[i + 1];
	}
	for (int i = 0; i < 12; ++i) {
		A[i].resize(sz[0]);
	}
	for (int i = 0; i < sz[0]; ++i) {
		cin >> A[11][i];
	}
	for (int i = 0; i < sz[0]; ++i) {
		int x = i;
		for (int j = 0; j < 11; ++j) {
			B[j] = x / sz[j + 1];
			x %= sz[j + 1];
		}
		for (int j = 10; j >= 0; --j) {
			A[j][i] = (B[j] ? A[j][i - sz[j + 1]] : 0) + A[j + 1][i];
		}
	}
	int Q{};
	cin >> Q;
	while (Q--) {
		for (int i = 0; i < 11; ++i) {
			cin >> B[i];
			--B[i];
		}
		for (int i = 0; i < 11; ++i) {
			cin >> C[i];
			--C[i];
		}
		ll ans = solve(0, 0, 1);
		cout << ans << "\n";
	}
	return 0;
}
