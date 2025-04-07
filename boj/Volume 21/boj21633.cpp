#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{};
	cin >> K;
	double ans = min(max(2500 + K, 10000), 200000) / 100.0;
	cout << fixed << setprecision(2);
	cout << ans << "\n";
	return 0;
}
