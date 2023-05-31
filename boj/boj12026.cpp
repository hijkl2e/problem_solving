#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	vector<int> dp(N, INF);
	dp[0] = 0;
	for (int i = 0; i < N; ++i) {
		char c = S[i] == 'B' ? 'O' : S[i] == 'O' ? 'J' : 'B';
		for (int j = i + 1; j < N; ++j) {
			if (S[j] == c) {
				dp[j] = min(dp[j], dp[i] + (j - i) * (j - i));
			}
		}
	}
	cout << (dp[N - 1] == INF ? -1 : dp[N - 1]) << "\n";
	return 0;
}
