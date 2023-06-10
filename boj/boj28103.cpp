#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, M{}, X{};
	cin >> N >> M >> X;
	vector<ll> A(M);
	for (int i = 0; i < M; ++i) {
		cin >> A[i];
	}
	vector<ll> B(M);
	for (int i = 0; i < M - 1; ++i) {
		B[i] = min((X - N * A[M - 1]) / (A[i] - A[M - 1]), N);
		N -= B[i];
		X -= B[i] * A[i];
	}
	B[M - 1] = N;
	for (int i = 0; i < M; ++i) {
		cout << B[i] << (i == M - 1 ? "\n" : " ");
	}
	return 0;
}
