#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	S = "#" + S;
	vector<deque<bool>> dp1(S.size(), deque<bool>(S.size()));
	dp1.back().back() = true;
	for (int i = S.size() - 2; i > 0; --i) {
		dp1[i][i] = true;
		dp1[i][i + 1] = S[i] == S[i + 1];
		for (int j = i + 2; j < S.size(); ++j) {
			dp1[i][j] = dp1[i + 1][j - 1] && S[i] == S[j];
		}
	}
	vector<int> dp2(S.size(), INF);
	dp2[0] = 0;
	for (int i = 1; i < dp2.size(); ++i) {
		for (int j = 1; j <= i; ++j) {
			if (dp1[j][i]) {
				dp2[i] = min(dp2[i], dp2[j - 1] + 1);
			}
		}
	}
	cout << dp2.back() << "\n";
	return 0;
}
