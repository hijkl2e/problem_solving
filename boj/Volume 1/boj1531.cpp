#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> A(101, vector<int>(101));
	while (N--) {
		int x1{}, y1{}, x2{}, y2{};
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i <= x2; ++i) {
			for (int j = y1; j <= y2; ++j) {
				++A[i][j];
			}
		}
	}
	int ans{};
	for (int i = 1; i < 101; ++i) {
		for (int j = 1; j < 101; ++j) {
			if (A[i][j] > M) {
				++ans;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
