#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	double ans{};
	for (int i = 1; i <= N; ++i) {
		ans += 1.0 / i;
	}
	ans *= N;
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
