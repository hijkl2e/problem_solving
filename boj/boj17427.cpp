#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	ll ans{};
	for (int i = 1; i <= N; ++i) {
		ans += N / i * i;
	}
	cout << ans << "\n";
	return 0;
}
