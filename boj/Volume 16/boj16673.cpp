#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int C{}, K{}, P{};
	cin >> C >> K >> P;
	int ans = K * C * (C + 1) / 2 + P * C * (C + 1) * (2 * C + 1) / 6;
	cout << ans << "\n";
	return 0;
}
