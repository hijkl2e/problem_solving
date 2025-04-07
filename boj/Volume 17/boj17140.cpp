#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int r{}, c{}, k{};
	cin >> r >> c >> k;
	--r, --c;
	vector<vector<int>> A(100, vector<int>(100));
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> A[i][j];
		}
	}
	if (A[r][c] == k) {
		cout << "0\n";
		return 0;
	}
	vector<int> B(101);
	vector<ii> C;
	int rsz = 3, csz = 3, ans = -1;
	for (int t = 1; t < 101; ++t) {
		if (rsz >= csz) {
			csz = 0;
			for (int i = 0; i < 100; ++i) {
				fill(B.begin(), B.end(), 0);
				for (int j = 0; j < 100; ++j) {
					++B[A[i][j]];
				}
				C.clear();
				for (int j = 1; j < 101; ++j) {
					if (B[j]) {
						C.push_back({B[j], j});
					}
				}
				sort(C.begin(), C.end());
				fill(A[i].begin(), A[i].end(), 0);
				for (int j = 0; j < C.size() && j < 50; ++j) {
					A[i][2 * j] = C[j].second;
					A[i][2 * j + 1] = C[j].first;
				}
				csz = max(csz, 2 * min<int>(C.size(), 50));
			}
		} else {
			rsz = 0;
			for (int j = 0; j < 100; ++j) {
				fill(B.begin(), B.end(), 0);
				for (int i = 0; i < 100; ++i) {
					++B[A[i][j]];
				}
				C.clear();
				for (int j = 1; j < 101; ++j) {
					if (B[j]) {
						C.push_back({B[j], j});
					}
				}
				sort(C.begin(), C.end());
				for (int i = 0; i < 100; ++i) {
					A[i][j] = 0;
				}
				for (int i = 0; i < C.size() && i < 50; ++i) {
					A[2 * i][j] = C[i].second;
					A[2 * i + 1][j] = C[i].first;
				}
				rsz = max(rsz, 2 * min<int>(C.size(), 50));
			}
		}
		if (A[r][c] == k) {
			ans = t;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
