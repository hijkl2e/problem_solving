#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<double> P(10);
	for (int i = 0; i < 10; ++i) {
		cin >> P[i];
		P[i] *= 10;
	}
	sort(P.begin(), P.end());
	double ans = 1;
	for (int i = 1; i < 10; ++i) {
		ans *= P[i];
	}
	ans /= 362880;
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
