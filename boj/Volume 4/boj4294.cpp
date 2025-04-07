#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	double K{}, L{}, S{}, W{};
	while (cin >> K >> L >> S >> W, K) {
		double x = 2 * 9.81 * S;
		if (S > L) {
			x -= K * (S - L) * (S - L) / W;
		}
		if (x + EPS < 0) {
			cout << "Stuck in the air.\n";
		} else if (x - EPS > 100) {
			cout << "Killed by the impact.\n";
		} else {
			cout << "James Bond survives.\n";
		}
	}
	return 0;
}
