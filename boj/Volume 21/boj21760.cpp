#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{}, K{}, D{};
		cin >> N >> M >> K >> D;
		int x = K * N * M * (M - 1) / 2;
		x += (N * M) * (N * M - 1) / 2 - x / K;
		int ans{};
		if (x > D) {
			ans = -1;
		} else {
			ans = D - D % x;
		}
		cout << ans << "\n";
	}
	return 0;
}
