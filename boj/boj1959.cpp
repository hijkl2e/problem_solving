#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	ll ans = 2LL * min(N, M) - (N > M ? 1 : 2);
	int x{}, y{};
	if (N > M) {
		x = M % 2 ? (N - M / 2) : (M / 2 + 1);
		y = (M + 1) / 2;
	} else {
		x = N / 2 + 1;
		y = N % 2 ? (M - N / 2) : (N / 2);
	}
	cout << ans << "\n";
	cout << x << " " << y << "\n";
	return 0;
}
