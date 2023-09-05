#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(8);
	vector<int> B(8);
	for (int i = 0; i < 8; ++i) {
		cin >> A[i] >> B[i];
	}
	ll x1 = A[0] + A[1] + A[2] + A[3];
	ll y1 = B[0] + B[1] + B[2] + B[3];
	ll x2 = A[4] + A[5] + A[6] + A[7];
	ll y2 = B[4] + B[5] + B[6] + B[7];
	if (x1 > x2) {
		swap(x1, x2);
		swap(y1, y2);
	}
	ll n1 = y2 - y1;
	ll d1 = x2 - x1;
	ll n2 = x2 * y1 - x1 * y2;
	ll d2 = 4 * (x2 - x1);
	ll g = gcd(n1, d1);
	n1 /= g, d1 /= g;
	g = gcd(n2, d2);
	n2 /= g, d2 /= g;
	cout << n1;
	if (d1 > 1) {
		cout << "/" << d1;
	}
	cout << " " << n2;
	if (d2 > 1) {
		cout << "/" << d2;
	}
	cout << "\n";
	return 0;
}
