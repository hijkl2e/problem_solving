#include <bits/stdc++.h>

using namespace std;

bool A[7][7][7];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	while (M--) {
		int x{}, y{}, z{};
		cin >> x >> y >> z;
		A[x][y][z] = true;
	}
	int ans{};
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			for (int k = 1; k <= N; ++k) {
				if (A[i][j][k] && A[i + 1][j][k] && A[i - 1][j][k]
						&& A[i][j + 1][k] && A[i][j - 1][k] && A[i][j][k + 1] && A[i][j][k - 1]) {
					++ans;
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
