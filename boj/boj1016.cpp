#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll X{}, Y{};
	cin >> X >> Y;
	deque<bool> A(Y - X + 1, true);
	for (ll i = 2; i * i <= Y; ++i) {
		ll j = i * i;
		for (ll k = X + (j - X % j) % j; k <= Y; k += j) {
			A[k - X] = false;
		}
	}
	int ans = accumulate(A.begin(), A.end(), 0);
	cout << ans << "\n";
	return 0;
}
