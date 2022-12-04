#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<ll> K(N);
		vector<ll> D(N);
		vector<ll> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> K[i] >> D[i] >> A[i];
		}
		int k{}, d{}, a{};
		cin >> k >> d >> a;
		ll ans{};
		for (int i = 0; i < N; ++i) {
			ans += max(k * K[i] - d * D[i] + a * A[i], 0LL);
		}
		cout << ans << "\n";
	}
	return 0;
}
