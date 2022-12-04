#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<ll> A(3);
	vector<ll> B(3);
	for (int i = 0; i < 3; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < 3; ++i) {
		cin >> B[i];
	}
	ll ans{};
	for (int j = 0; j < 3; ++j) {
		for (int i = 0; i < 3; ++i) {
			if (j) {
				B[i] += B[(i + 2) % 3] / 3;
				B[(i + 2) % 3] %= 3;
			}
			ll minv = min(A[i], B[i]);
			A[i] -= minv;
			B[i] -= minv;
			ans += minv;
		}
	}
	cout << ans << "\n";
	return 0;
}
