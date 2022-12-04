#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, P{};
	cin >> N >> P;
	vector<vector<int>> A(5, vector<int>(14));
	int ans = -1;
	for (int i = 0; i < N; ++i) {
		int x{}, y{};
		cin >> x >> y;
		++A[x][y];
		bool yes{};
		for (int j = 1; j < 5; ++j) {
			for (int k = 1; k < 12; ++k) {
				if (A[j][k] && A[j][k + 1] && A[j][k + 2]) {
					yes = true;
				}
			}
		}
		if (yes) {
			ans = max(i - P + 1, 1);
			break;
		}
	}
	if (ans == -1) {
		cout << "neibb\n";
	} else {
		cout << ans << "\n";
	}
	return 0;
}
