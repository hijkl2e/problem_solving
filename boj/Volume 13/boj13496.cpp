#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		if (tc > 1) {
			cout << "\n";
		}
		int N{}, S{}, D{};
		cin >> N >> S >> D;
		int ans{};
		while (N--) {
			int d{}, v{};
			cin >> d >> v;
			if (d <= D * S) {
				ans += v;
			}
		}
		cout << "Data Set " << tc << ":\n";
		cout << ans << "\n";
	}
	return 0;
}
