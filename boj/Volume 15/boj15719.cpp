#include <bits/stdc++.h>

using namespace std;

int solve(int N) {
	int ret{};
	for (int i = N / 4 * 4; i <= N; ++i) {
		ret ^= i;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans = solve(N - 1);
	for (int i = 0; i < N; ++i) {
		int x{};
		cin >> x;
		ans ^= x;
	}
	cout << ans << "\n";
	return 0;
}
