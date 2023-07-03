#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, P{};
	cin >> N >> P;
	int ans = P;
	if (N >= 5) {
		ans = min(ans, max(P - 500, 0));
	}
	if (N >= 10) {
		ans = min(ans, P / 10 * 9);
	}
	if (N >= 15) {
		ans = min(ans, max(P - 2000, 0));
	}
	if (N >= 20) {
		ans = min(ans, P / 4 * 3);
	}
	cout << ans << "\n";
	return 0;
}
