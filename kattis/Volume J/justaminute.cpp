#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int M_sum{}, S_sum{};
	while (N--) {
		int M{}, S{};
		cin >> M >> S;
		M_sum += M;
		S_sum += S;
	}
	double ans = S_sum / 60.0 / M_sum;
	if (ans - EPS > 1) {
		cout << fixed << setprecision(10);
		cout << ans << "\n";
	} else {
		cout << "measurement error\n";
	}
	return 0;
}
