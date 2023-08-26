#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int L{};
	cin >> L;
	double ans = sqrt(3) / 4 * L * L;
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
