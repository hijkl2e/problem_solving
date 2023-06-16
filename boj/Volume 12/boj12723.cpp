#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int N{};
		cin >> N;
		vector<ll> A(N);
		vector<ll> B(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		for (int i = 0; i < N; ++i) {
			cin >> B[i];
		}
		sort(A.begin(), A.end());
		sort(B.rbegin(), B.rend());
		ll ans{};
		for (int i = 0; i < N; ++i) {
			ans += A[i] * B[i];
		}
		cout << "Case #" << tc << ": " << ans << "\n";
	}
	return 0;
}
