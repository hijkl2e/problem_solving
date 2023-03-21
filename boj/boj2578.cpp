#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<int>> A(5, vector<int>(5));
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> A[i][j];
		}
	}
	vector<int> row(5);
	vector<int> col(5);
	vector<int> d1(9);
	vector<int> d2(9);
	int ans{}, cnt{};
	while (++ans) {
		int x{};
		cin >> x;
		int r{}, c{};
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (A[i][j] == x) {
					r = i, c = j;
				}
			}
		}
		cnt += ++row[r] == 5;
		cnt += ++col[c] == 5;
		cnt += ++d1[r + c] == 5;
		cnt += ++d2[r - c + 4] == 5;
		if (cnt > 2) {
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
