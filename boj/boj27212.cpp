#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<vector<int>> C(K + 1, vector<int>(K + 1));
	for (int i = 1; i <= K; ++i) {
		for (int j = 1; j <= K; ++j) {
			cin >> C[i][j];
		}
	}
	vector<int> A(N + 1);
	vector<int> B(M + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	for (int i = 1; i <= M; ++i) {
		cin >> B[i];
	}
	vector<vector<ll>> dp(N + 1, vector<ll>(M + 1));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + C[A[i]][B[j]]});
		}
	}
	cout << dp[N][M] << "\n";
	return 0;
}
