#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[i][j] != 'S') {
				continue;
			}
			int minv = 1e9;
			for (int k = 0; k < N; ++k) {
				for (int l = 0; l < N; ++l) {
					if (A[k][l] != 'H') {
						continue;
					}
					minv = min(minv, abs(i - k) + abs(j - l));
				}
			}
			ans = max(ans, minv);
		}
	}
	cout << ans << "\n";
	return 0;
}
