#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<ll> B(N, 1);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i == j) {
				continue;
			}
			B[i] = (B[i] * (A[i] - A[j])) % MOD;
		}
		B[i] = (B[i] + MOD) % MOD;
	}
	for (int i = 0; i < N; ++i) {
		cout << B[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
