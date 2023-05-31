#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	int ans = -1;
	for (int i = 1; i <= M; ++i) {
		int t{}, r{};
		cin >> t >> r;
		K -= r;
		if (K < 0) {
			ans = i;
			break;
		}
	}
	if (ans == -1) {
		cout << "-1\n";
	} else {
		cout << ans << " 1\n";
	}
	return 0;
}
