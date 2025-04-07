#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll p1{}, q1{}, p2{}, q2{};
	cin >> p1 >> q1 >> p2 >> q2;
	cout << ((p1 * p2) % (2 * q1 * q2) == 0) << "\n";
	return 0;
}
