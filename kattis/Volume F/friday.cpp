#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int D{}, M{};
		cin >> D >> M;
		int start{}, ans{};
		while (M--) {
			int d{};
			cin >> d;
			if (start == 0 && d >= 13) {
				++ans;
			}
			start = (start + d) % 7;
		}
		cout << ans << "\n";
	}
	return 0;
}
