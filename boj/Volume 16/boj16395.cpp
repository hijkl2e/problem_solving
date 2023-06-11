#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<vector<int>> nCr(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		nCr[i][0] = nCr[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			nCr[i][j] = nCr[i - 1][j] + nCr[i - 1][j - 1];
		}
	}
	cout << nCr[N - 1][K - 1] << "\n";
	return 0;
}
