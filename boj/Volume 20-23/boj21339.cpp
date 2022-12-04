#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{}, D{}, S{};
	cin >> N >> K >> D >> S;
	double ans = (N * D - K * S) * 1.0 / (N - K);
	if (ans < 0 || ans > 100) {
		cout << "impossible\n";
	} else {
		cout << fixed << setprecision(10);
		cout << ans << "\n";
	}
	return 0;
}
