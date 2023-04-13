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
	ll K{};
	cin >> K;
	ll maxv{};
	for (int i = 1; i < N; ++i) {
		if (A[i - 1] > A[i]) {
			K -= A[i - 1] - A[i];
			A[i] = A[i - 1];
			maxv = A[i];
		}
	}
	for (int i = 0; i < N; ++i) {
		if (A[i] < maxv) {
			K -= maxv - A[i];
			A[i] = maxv;
		}
	}
	if (K < 0) {
		cout << "0\n";
		return 0;
	}
	ll ans = maxv > 0;
	for (int i = 0, j = 1; i < N; i = j++) {
		while (j < N && A[i] == A[j]) {
			++j;
		}
		if (j == N) {
			ans += K / N;
			break;
		}
		ll x = min(K / j, A[j] - A[i]);
		ans += x;
		K -= j * x;
	}
	cout << ans << "\n";
	return 0;
}
