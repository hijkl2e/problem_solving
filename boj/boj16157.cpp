#include <bits/stdc++.h>

using namespace std;

int dp[101][101][4];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	vector<int> A;
	for (int i = 0, j = 1; i < N; i = j++) {
		while (j < N && S[i] == S[j]) {
			++j;
		}
		A.push_back(S[i] == 'R' ? 1 : S[i] == 'G' ? 2 : 3);
	}
	N = A.size();
	for (int i = N - 1; i >= 0; --i) {
		for (int j = 0; j < 4; ++j) {
			dp[i][i][j] = A[i] != j;
		}
		for (int j = i + 1; j < N; ++j) {
			for (int k = 0; k < 4; ++k) {
				dp[i][j][k] = dp[i][i][k] + dp[i + 1][j][k];
				for (int l = i + 1; l <= j; ++l) {
					if (A[i] == A[l]) {
						dp[i][j][k] = min(dp[i][j][k], dp[i + 1][l - 1][A[i]] + dp[l + 1][j][k] + 1);
					}
				}
			}
		}
	}
	cout << dp[0][N - 1][0] << "\n";
	return 0;
}
