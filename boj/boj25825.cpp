#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<int>> A(12, vector<int>(12));
	for (int i = 0; i < 12; ++i) {
		for (int j = 0; j < 12; ++j) {
			cin >> A[i][j];
		}
	}
	vector<vector<int>> D(64, vector<int>(12, INF));
	for (int i = 0; i < 12; ++i) {
		D[1 << (i / 2)][i] = A[i ^ 1][i];
	}
	for (int i = 1; i < 64; ++i) {
		for (int j = 0; j < 12; ++j) {
			if (D[i][j] == INF) {
				continue;
			}
			for (int k = 0; k < 12; ++k) {
				if (i & (1 << (k / 2))) {
					continue;
				}
				int &val = D[i | (1 << (k / 2))][k];
				val = min(val, D[i][j] + A[j][k ^ 1] + A[k ^ 1][k]);
			}
		}
	}
	int ans = *min_element(D.back().begin(), D.back().end());
	cout << ans << "\n";
	return 0;
}
