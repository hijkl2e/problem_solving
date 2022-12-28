#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	S = "#" + S;
	int M{};
	cin >> M;
	vector<string> A(M);
	vector<int> X(M);
	for (int i = 0; i < M; ++i) {
		cin >> A[i] >> X[i];
	}
	vector<vector<int>> B(S.size());
	for (int i = 0; i < M; ++i) {
		auto j = S.find(A[i]);
		while (j != -1) {
			B[j + A[i].size() - 1].push_back(i);
			j = S.find(A[i], j + 1);
		}
	}
	vector<int> dp(S.size());
	for (int i = 1; i < S.size(); ++i) {
		dp[i] = dp[i - 1] + 1;
		for (int j : B[i]) {
			dp[i] = max(dp[i], dp[i - A[j].size()] + X[j]);
		}
	}
	cout << dp.back() << "\n";
	return 0;
}
