#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	ll ans = 1;
	for (int i = 1; i < N;) {
		int x = (N - 1) / i;
		int j = (N - 1) / x + 1;
		ans += (j - i) * (x + 1);
		i = j;
	}
	cout << ans << "\n";
	return 0;
}
