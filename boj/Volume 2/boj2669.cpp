#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<deque<bool>> A(101, deque<bool>(101));
	for (int k = 0; k < 4; ++k) {
		int x1{}, y1{}, x2{}, y2{};
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i < x2; ++i) {
			for (int j = y1; j < y2; ++j) {
				A[i][j] = true;
			}
		}
	}
	int ans{};
	for (int i = 0; i < 101; ++i) {
		ans += accumulate(A[i].begin(), A[i].end(), 0);
	}
	cout << ans << "\n";
	return 0;
}
