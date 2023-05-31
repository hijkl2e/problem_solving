#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, X{};
	cin >> N >> X;
	vector<ll> A(N);
	vector<ll> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	ll sum{};
	for (int i = 0; i < N; ++i) {
		sum += B[i];
		if (sum < A[i]) {
			cout << "-1\n";
			return 0;
		}
	}
	ll ans = (sum - A[N - 1]) / X;
	cout << ans << "\n";
	return 0;
}
