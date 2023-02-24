#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{};
	cin >> N;
	ll ans = N / 5 + (N % 5 ? N % 5 % 2 ? 1 : 2 : 0);
	if (N == 1 || N == 2 || N == 4 || N == 7) {
		ans = -1;
	}
	cout << ans << "\n";
	return 0;
}
