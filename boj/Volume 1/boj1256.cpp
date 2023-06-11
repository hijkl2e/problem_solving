#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	N += M;
	vector<vector<int>> nCr(N + 1, vector<int>(N + 1));
	for (int i = 0; i <= N; ++i) {
		nCr[i][0] = nCr[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			nCr[i][j] = min(nCr[i - 1][j] + nCr[i - 1][j - 1], INF);
		}
	}
	if (K > nCr[N][M]) {
		cout << "-1\n";
		return 0;
	}
	string ans(N, 'a');
	for (int i = 0; i < N; ++i) {
		if (K > nCr[N - i - 1][M]) {
			K -= nCr[N - i - 1][M--];
			ans[i] = 'z';
		}
	}
	cout << ans << "\n";
	return 0;
}
