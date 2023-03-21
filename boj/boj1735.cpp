#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n1{}, d1{}, n2{}, d2{};
	cin >> n1 >> d1 >> n2 >> d2;
	int n = n1 * d2 + n2 * d1;
	int d = d1 * d2;
	int g = gcd(n, d);
	n /= g, d /= g;
	cout << n << " " << d << "\n";
	return 0;
}
