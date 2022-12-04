#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	double X{};
	cin >> X;
	int x = X * 10000 + EPS;
	x = 100000 - x;
	if (x <= 0) {
		cout << "No solution\n";
		return 0;
	}
	vector<int> A;
	for (ll i = 10; i < 1000000000; i *= 10) {
		for (int j = 1; j < 10; ++j) {
			ll val = (i - 1) * j * 10000;
			if (val % x == 0 && to_string(val / x)[0] == j + '0') {
				A.push_back(val / x);
			}
		}
	}
	if (A.empty()) {
		cout << "No solution\n";
	} else {
		for (int x : A) {
			cout << x << "\n";
		}
	}
	return 0;
}
