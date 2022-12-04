#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<int>> ans{
		{1, 3, 6, 10}, {3, 13, 40, 108},
		{6, 40, 217, 1109}, {10, 108, 1109, 10977}
	};
	int R{}, C{};
	cin >> R >> C;
	cout << ans[R - 1][C - 1] << "\n";
	return 0;
}
