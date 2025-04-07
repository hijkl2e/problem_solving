#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> A(4);
	for (int i = 0; i < 4; ++i) {
		getline(cin, A[i]);
	}
	int ans{};
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (A[i][j] == '.') {
				continue;
			}
			ans += abs(i - (A[i][j] - 'A') / 4) + abs(j - (A[i][j] - 'A') % 4);
		}
	}
	cout << ans << "\n";
	return 0;
}
