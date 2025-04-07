#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	cin.ignore();
	vector<vector<int>> A(N + 1, vector<int>(M + 1));
	for (int i = 1; i <= N; ++i) {
		string s;
		getline(cin, s);
		for (int j = 1; j <= M; ++j) {
			A[i][j] = s[j - 1] == ((i + j) % 2 ? 'B' : 'W');
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			A[i][j] += A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1];
		}
	}
	int ans = 1e9;
	for (int i = K; i <= N; ++i) {
		for (int j = K; j <= M; ++j) {
			int sum = A[i][j] - A[i - K][j] - A[i][j - K] + A[i - K][j - K];
			ans = min({ans, sum, abs(K * K - sum)});
		}
	}
	cout << ans << "\n";
	return 0;
}
