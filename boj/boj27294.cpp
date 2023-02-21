#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{}, S{};
	cin >> T >> S;
	int ans = 12 <= T && T <= 16 && S == 0 ? 320 : 280;
	cout << ans << "\n";
	return 0;
}
