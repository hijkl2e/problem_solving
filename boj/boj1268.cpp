#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(N, vector<int>(5));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> A[i][j];
		}
	}
	int maxv{}, maxi{};
	for (int i = 0; i < N; ++i) {
		int cnt{};
		for (int j = 0; j < N; ++j) {
			bool yes{};
			for (int k = 0; k < 5; ++k) {
				if (A[i][k] == A[j][k]) {
					yes = true;
					break;
				}
			}
			if (yes) {
				++cnt;
			}
		}
		if (maxv < cnt) {
			maxv = cnt;
			maxi = i + 1;
		}
	}
	cout << maxi << "\n";
	return 0;
}
