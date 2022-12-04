#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{};
	cin >> N;
	int ans = 1;
	while (N > 1) {
		if (N % 2) {
			N = 3 * N + 1;
		} else {
			N /= 2;
		}
		++ans;
	}
	cout << ans << "\n";
	return 0;
}
