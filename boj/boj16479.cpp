#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{}, d1{}, d2{};
	cin >> K >> d1 >> d2;
	double ans = K * K - (d1 - d2) * (d1 - d2) / 4.0;
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
