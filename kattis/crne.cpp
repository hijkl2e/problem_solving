#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{};
	cin >> N;
	ll ans = ((N + 1) / 2) * ((N + 1) / 2 + 1) + (N % 2 == 0 ? N / 2 + 1 : 0);
	cout << ans << "\n";
	return 0;
}
