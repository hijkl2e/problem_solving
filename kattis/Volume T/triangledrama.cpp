#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	iii maxi{1, 2, 3};
	int maxv{};
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			for (int k = j + 1; k < N; ++k) {
				int val = A[i][j] * A[j][k] * A[k][i];
				if (maxv < val) {
					maxi = {i + 1, j + 1, k + 1};
					maxv = val;
				}
			}
		}
	}
	auto &[i, j, k] = maxi;
	cout << i << " " << j << " " << k << "\n";
	return 0;
}
