#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const double PI = acos(-1);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{};
	cin >> N;
	double ans = 2 * sqrt(N) * sqrt(PI);
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
