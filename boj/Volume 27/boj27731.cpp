#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

const ll MOD = 1e9 + 7;

int N, M, K;
vector<int> A;
vector<ll> B, D;
vector<ii> C;

void solve(int n, int s, ll x, bool f) {
	if (n == N || f) {
		ll y = 1;
		for (int i = 0; i < n; ++i) {
			y = y * (N - i) % MOD;
		}
		for (auto &p : C) {
			y = y * D[p.second] % MOD;
		}
		B[x] = (B[x] + y) % MOD;
		if (n == N) {
			return;
		}
	}
	for (int i = s; i < A.size(); ++i) {
		ll y = x * A[i];
		if (y > K) {
			break;
		}
		if (C.size() && C.back().first == i) {
			++C.back().second;
		} else {
			C.push_back({i, 1});
		}
		solve(n + 1, i, y, f);
		if (--C.back().second == 0) {
			C.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	D = {
		-1, 1, 500000004, 166666668, 41666667, 808333339, 301388891, 900198419, 487524805, 831947206,
		283194722, 571199524, 380933296, 490841026, 320774361, 821384963, 738836565, 514049213
	};
	cin >> N >> M >> K;
	A.resize(M);
	for (int i = 0; i < M; ++i) {
		cin >> A[i];
	}
	while (A.size() && A.back() > K) {
		A.pop_back();
	}
	B.resize(K + 1);
	if (A.size() && (A[0] == 1 || N < 18)) {
		solve(0, A[0] == 1, 1, A[0] == 1);
	}
	for (int i = 1; i <= K; ++i) {
		cout << B[i] << (i == K ? "\n" : " ");
	}
	return 0;
}
