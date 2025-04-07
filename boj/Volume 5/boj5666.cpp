#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	while (cin >> N >> M) {
		double ans = N * 1.0 / M;
		cout << fixed << setprecision(2);
		cout << ans << "\n";
	}
	return 0;
}
