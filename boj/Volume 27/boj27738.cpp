#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{};
	cin >> N;
	vector<ll> A(6);
	for (int i = 0; i < 6; ++i) {
		cin >> A[i];
	}
	ll X{};
	for (ll i = N / A[5] * A[5] + 1; i <= N; ++i) {
		if (i % A[0] == 0) {
			X += i;
		}
		if (i % A[1] == 0) {
			X %= i;
		}
		if (i % A[2] == 0) {
			X &= i;
		}
		if (i % A[3] == 0) {
			X ^= i;
		}
		if (i % A[4] == 0) {
			X |= i;
		}
	}
	cout << X << "\n";
	return 0;
}
