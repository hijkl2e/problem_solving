#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int M{}, N{}, K{};
		cin >> M >> N >> K;
		int W = M * N / 2;
		int B = M * N / 2;
		vector<ii> A(K);
		for (int i = 0; i < K; ++i) {
			int x{}, y{};
			cin >> x >> y;
			if ((x + y) % 2) {
				--W;
			} else {
				--B;
			}
			A[i] = {x, y};
		}
		for (auto &[x1, y1] : vector<ii>{{1, 1}, {M, 1}, {1, N}, {M, N}}) {
			int cnt{};
			for (auto &[x2, y2] : A) {
				if (abs(x2 - x1) + abs(y2 - y1) == 1) {
					++cnt;
				} else if (x1 == x2 && y1 == y2) {
					cnt = -1;
					break;
				}
			}
			if (cnt == 2) {
				if ((x1 + y1) % 2) {
					--W;
				} else {
					--B;
				}
			}
		}
		int ans = min(W, B);
		cout << ans << "\n";
	}
	return 0;
}
