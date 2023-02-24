#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	ll ans = 1;
	for (int i = 1; i <= N; ++i) {
		ans *= i;
	}
	cout << ans << "\n";
	return 0;
}
