#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<deque<bool>> A(101, deque<bool>(101));
	int N{};
	cin >> N;
	while (N--) {
		int x{}, y{};
		cin >> x >> y;
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				A[x + i][y + j] = true;
			}
		}
	}
	vector<vector<int>> B(101, vector<int>(101));
	for (int i = 1; i < 101; ++i) {
		for (int j = 1; j < 101; ++j) {
			B[i][j] = A[i][j] ? B[i][j - 1] + 1 : 0;
		}
	}
	int ans{};
	for (int k = 1; k < 101; ++k) {
		for (int j = k; j < 101; ++j) {
			int sum{};
			for (int i = 1; i < 101; ++i) {
				if (B[i][j] >= k) {
					sum += k;
					ans = max(ans, sum);
				} else {
					sum = 0;
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
