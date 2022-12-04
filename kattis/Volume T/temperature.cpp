#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int X{}, Y{};
	cin >> X >> Y;
	if (Y == 1) {
		cout << (X == 0 ? "ALL GOOD" : "IMPOSSIBLE") << "\n";
	} else {
		double ans = -X / (Y - 1.0);
		cout << fixed << setprecision(10);
		cout << ans << "\n";
	}
	return 0;
}
