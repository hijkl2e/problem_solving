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
	vector<ll> B(60);
	for (int i = 0; i < N; ++i) {
		for (int j = 59; j >= 0; --j) {
			if (A[i] & (1LL << j)) {
				if (B[j]) {
					A[i] ^= B[j];
				} else {
					B[j] = A[i];
					break;
				}
			}
		}
	}
	ll ans{};
	for (int i = 59; i >= 0; --i) {
		if ((ans & (1LL << i)) == 0) {
			ans ^= B[i];
		}
	}
	cout << ans << "\n";
	return 0;
}
