#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, k{}, x{};
	cin >> a >> b >> k >> x;
	int ans = max(min(b, k + x) - max(a, k - x), -1) + 1;
	if (ans) {
		cout << ans << "\n";
	} else {
		cout << "IMPOSSIBLE\n";
	}
	return 0;
}
