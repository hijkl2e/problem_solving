#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	ll ans = 1LL * (N - 1) * (N - 1);
	cout << ans << "\n";
	for (int i = 2; i <= N; ++i) {
		cout << "1 " << i << "\n";
	}
	return 0;
}
