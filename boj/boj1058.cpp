#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

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
	vector<vector<int>> D(N, vector<int>(N, INF));
	for (int i = 0; i < N; ++i) {
		D[i][i] = 0;
		for (int j = 0; j < N; ++j) {
			if (A[i][j] == 'Y') {
				D[i][j] = 1;
			}
		}
	}
	for (int k = 0; k < N; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		ans = max<int>(ans, count(D[i].begin(), D[i].end(), 1) + count(D[i].begin(), D[i].end(), 2));
	}
	cout << ans << "\n";
	return 0;
}
