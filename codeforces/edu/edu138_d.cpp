#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 998244353;

deque<bool> sieve(int N) {
	deque<bool> p(N + 1, true);
	p[0] = p[1] = false;
	for (int i = 2; i * i <= N; ++i) {
		if (p[i]) {
			for (int j = 2 * i; j <= N; j += i) {
				p[j] = false;
			}
		}
	}
	return p;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	ll M{};
	cin >> N >> M;
	deque<bool> p = sieve(N);
	vector<ll> A(N + 1);
	A[1] = 1;
	for (int i = 2; i <= N; ++i) {
		A[i] = A[i - 1];
		if (A[i] <= M && p[i]) {
			A[i] *= i;
		}
	}
	vector<__int128> B(N + 1);
	B[1] = M % MOD;
	for (int i = 2; i <= N; ++i) {
		B[i] = B[i - 1] * M % MOD;
	}
	ll ans = accumulate(B.begin(), B.end(), 0LL) % MOD;
	vector<__int128> C(N + 1);
	C[1] = M % MOD;
	for (int i = 2; i <= N; ++i) {
		C[i] = C[i - 1] * (M / A[i]) % MOD;
	}
	ans = (ans - accumulate(C.begin(), C.end(), 0LL) % MOD + MOD) % MOD;
	cout << ans << "\n";
	return 0;
}
