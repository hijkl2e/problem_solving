#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll solve(ll x) {
	ll ret{};
	for (int i = 0; i < 54; ++i) {
		ret += x / (1LL << (i + 1)) * (1LL << i);
		ret += max(x % (1LL << (i + 1)) - (1LL << i), 0LL);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll A{}, B{};
	cin >> A >> B;
	ll ans = solve(B + 1) - solve(A);
	cout << ans << "\n";
	return 0;
}
