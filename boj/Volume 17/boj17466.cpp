#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, P{};
	cin >> N >> P;
	ll ans = 1;
	for (int i = 1; i <= N; ++i) {
		ans = ans * i % P;
	}
	cout << ans << "\n";
	return 0;
}
