#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int h{}, w{}, x{}, y{};
	cin >> h >> w >> x >> y;
	vector<vector<int>> A(h + x, vector<int>(w + y));
	for (int i = 0; i < A.size(); ++i) {
		for (int j = 0; j < A[i].size(); ++j) {
			cin >> A[i][j];
		}
	}
	for (int i = x; i < h; ++i) {
		for (int j = y; j < w; ++j) {
			A[i][j] -= A[i - x][j - y];
		}
	}
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cout << A[i][j] << (j == w - 1 ? "\n" : " ");
		}
	}
	return 0;
}
