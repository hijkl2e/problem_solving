#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<ll> A(7);
	for (int i = 0; i < 7; ++i) {
		cin >> A[i];
	}
	ll ans = (A[0] * A[1] + A[2] * A[3]) * (A[4] * A[5] * A[6]);
	cout << ans << "\n";
	return 0;
}
