#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{};
	cin >> N;
	double ans = 4 * sqrt(N);
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
