#include <bits/stdc++.h>

using namespace std;

int N, K;

int solve(int s, int n, int k, int x, int y) {
	if (s == 0) {
		return 0;
	}
	int l = (n - k) / 2;
	if (l <= x && x < n - l && l <= y && y < n - l) {
		return 1;
	}
	n /= N, k /= N;
	return solve(s - 1, n, k, x % n, y % n);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int s{}, r1{}, r2{}, c1{}, c2{};
	cin >> s >> N >> K >> r1 >> r2 >> c1 >> c2;
	int n = 1;
	for (int i = 0; i < s; ++i) {
		n *= N;
	}
	int k = n / N * K;
	for (int i = r1; i <= r2; ++i) {
		for (int j = c1; j <= c2; ++j) {
			cout << solve(s, n, k, i, j);
		}
		cout << "\n";
	}
	return 0;
}
