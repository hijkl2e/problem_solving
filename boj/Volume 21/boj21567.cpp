#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{};
	cin >> a >> b >> c;
	ll x = 1LL * a * b * c;
	vector<int> A(10);
	while (x) {
		++A[x % 10];
		x /= 10;
	}
	for (int i = 0; i < 10; ++i) {
		cout << A[i] << "\n";
	}
	return 0;
}
