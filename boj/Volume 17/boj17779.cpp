#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	int ans = INF;
	vector<int> B(5);
	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			for (int d1 = 1; x + d1 < N && y - d1 >= 0; ++d1) {
				for (int d2 = 1; x + d1 + d2 < N && y + d2 < N; ++d2) {
					fill(B.begin(), B.end(), 0);
					for (int i = 0; i < N; ++i) {
						for (int j = 0; j < N; ++j) {
							int z{};
							if (x + y <= i + j && i + j <= x + y + 2 * d2
									&& x - y <= i - j && i - j <= x - y + 2 * d1) {
								z = 4;
							} else if (i < x + d1 && j <= y && i + j < x + y) {
								z = 0;
							} else if (i <= x + d2 && j > y && i - j < x - y) {
								z = 1;
							} else if (i >= x + d1 && j < y - d1 + d2 && i - j > x - y + 2 * d1) {
								z = 2;
							} else {
								z = 3;
							}
							B[z] += A[i][j];
						}
					}
					ans = min(ans, *max_element(B.begin(), B.end())
							- *min_element(B.begin(), B.end()));
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
