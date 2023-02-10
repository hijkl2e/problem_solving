#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> A(N + 1);
	for (int i = 0; i <= N; ++i) {
		cin >> A[i];
		if (i && i < N) {
			cin >> A[i];
		}
	}
	ll ans{};
	for (int i = N - 1; i > 0; --i) {
		ans += A[i - 1] * A[i] * A[N];
	}
	cout << ans << "\n";
	return 0;
}
