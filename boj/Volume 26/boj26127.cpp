#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(K + 1);
	for (int i = 1; i <= K; ++i) {
		cin >> A[i];
	}
	cin.ignore();
	string S;
	getline(cin, S);
	S = "##" + S;
	vector<int> os(S.size());
	vector<int> xs(S.size());
	for (int i = 2; i < S.size(); ++i) {
		os[i] = os[i - 1] + (S[i] == 'O');
		xs[i] = xs[i - 1] + (S[i] == 'X');
	}
	vector<vector<ll>> dp(K + 1, vector<ll>(S.size()));
	dp[0][0] = 1;
	for (int i = 0; i <= K; ++i) {
		for (int j = A[i] + 1; j < S.size(); ++j) {
			dp[i][j] = S[j] == 'O' ? 0 : dp[i][j - 1];
			if (i == 0 || S[j - A[i]] == 'O'
					|| j + 1 < S.size() && S[j + 1] == 'O' || xs[j] - xs[j - A[i]]) {
				continue;
			}
			dp[i][j] = (dp[i][j] + dp[i - 1][j - A[i] - 1]) % MOD;
		}
	}
	cout << dp[K].back() << "\n";
	return 0;
}
