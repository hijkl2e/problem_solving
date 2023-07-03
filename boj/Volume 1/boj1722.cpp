#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int N;
vector<ll> fact;

void solve1() {
	ll K{};
	cin >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		A[i] = i + 1;
	}
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		int x = (K - 1) / fact[N - i - 1];
		B[i] = A[x];
		K -= x * fact[N - i - 1];
		A.erase(A.begin() + x);
	}
	for (int i = 0; i < N; ++i) {
		cout << B[i] << (i == N - 1 ? "\n" : " ");
	}
}

void solve2() {
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		B[i] = i + 1;
	}
	ll ans = 1;
	for (int i = 0; i < N; ++i) {
		int x = find(B.begin(), B.end(), A[i]) - B.begin();
		ans += x * fact[N - i - 1];
		B.erase(B.begin() + x);
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int q{};
	cin >> N >> q;
	fact.resize(N + 1);
	fact[0] = 1;
	for (int i = 1; i <= N; ++i) {
		fact[i] = i * fact[i - 1];
	}
	if (q == 1) {
		solve1();
	} else {
		solve2();
	}
	return 0;
}
