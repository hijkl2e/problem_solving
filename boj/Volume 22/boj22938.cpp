#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll x1{}, y1{}, r1{}, x2{}, y2{}, r2{};
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	ll d1 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
	ll d2 = (r1 + r2) * (r1 + r2);
	cout << (d1 < d2 ? "YES" : "NO") << "\n";
	return 0;
}
