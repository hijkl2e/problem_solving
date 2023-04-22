#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);
const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	while (N--) {
		double T{}, X{};
		cin >> T >> X;
		X *= PI / 180;
		T = 100 * T + 42.5 / tan(X);
		while (true) {
			double nt = T - 85 / tan(X);
			if (nt > 0) {
				T = nt;
				continue;
			}
			double d = 42.5 * abs(T + nt) / sqrt((T - nt) * (T - nt) + 7225);
			cout << (d < 16 + EPS ? "yes" : "no") << "\n";
			break;
		}
	}
	return 0;
}
