#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll solve(int r, int c) {
	ll ret = 1;
	if (r > c) {
		swap(r, c);
	}
	for (int i = c; i < r + c - 1; ++i) {
		ret *= i;
	}
	for (int i = 1; i < r; ++i) {
		ret /= i;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	ll ans{};
	if (K--) {
		int r = K / M, c = K % M;
		ans = solve(r + 1, c + 1) * solve(N - r, M - c);
	} else {
		ans = solve(N, M);
	}
	cout << ans << "\n";
	return 0;
}
