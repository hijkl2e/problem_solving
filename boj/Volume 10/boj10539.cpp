#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<ll> B(N);
	ll sum = B[0] = A[0];
	for (int i = 1; i < N; ++i) {
		B[i] = (i + 1) * A[i] - sum;
		sum += B[i];
	}
	for (int i = 0; i < N; ++i) {
		cout << B[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
