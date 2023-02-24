#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<ll>> A(N + 1, vector<ll>(N + 1));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> A[i][j];
		}
	}
	vector<vector<ll>> B(N + 2, vector<ll>(N + 2));
	B[0][0] = -1;
	while (M--) {
		int q{}, x1{}, y1{}, x2{}, y2{}, k{};
		cin >> q >> x1 >> y1 >> x2 >> y2;
		++x1, ++y1, ++x2, ++y2;
		if (q == 1) {
			cin >> k;
			B[x1][y1] += k;
			B[x2 + 1][y1] -= k;
			B[x1][y2 + 1] -= k;
			B[x2 + 1][y2 + 1] += k;
			continue;
		}
		if (B[0][0] == -1) {
			B[0][0] = 0;
			for (int k = 0; k < 2; ++k) {
				for (int i = 1; i <= N; ++i) {
					for (int j = 1; j <= N; ++j) {
						B[i][j] += (k ? A[i][j] : 0) + B[i - 1][j] + B[i][j - 1] - B[i - 1][j - 1];
					}
				}
			}
		}
		ll ans = B[x2][y2] - B[x1 - 1][y2] - B[x2][y1 - 1] + B[x1 - 1][y1 - 1];
		cout << ans << "\n";
	}
	return 0;
}
