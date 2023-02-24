#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	bitset<60001> dp;
	dp[15000] = true;
	while (N--) {
		int x{};
		cin >> x;
		dp |= dp << x;
		dp |= dp >> x;
	}
	int M{};
	cin >> M;
	while (M--) {
		int x{};
		cin >> x;
		cout << (dp[x + 15000] ? "Y" : "N") << (M ? " " : "\n");
	}
	return 0;
}
