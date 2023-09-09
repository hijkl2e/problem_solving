#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{};
	cin >> N;
	ll ans = N * (N - 1) / 2;
	cout << ans << "\n";
	return 0;
}
