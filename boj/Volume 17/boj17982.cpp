#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, R{}, K{};
	cin >> N >> R >> K;
	int ans = K + abs(R - K);
	if (N > ans) {
		ans += (N - ans + 1) / 2 * 2;
	}
	ans += R;
	cout << ans << "\n";
	return 0;
}
