#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		double R{}, B{}, M{};
		cin >> R >> B >> M;
		if (round(B * R + EPS) / 100 + EPS >= M) {
			cout << "impossible\n";
			continue;
		}
		int ans{};
		for (int i = 1; i <= 1200; ++i) {
			B += round(B * R + EPS) / 100;
			B -= M;
			if (B - EPS <= 0) {
				ans = i;
				break;
			}
		}
		if (ans) {
			cout << ans << "\n";
		} else {
			cout << "impossible\n";
		}
	}
	return 0;
}
