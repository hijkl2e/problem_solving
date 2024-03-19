#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	S = "#" + S;
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	deque<bool> dp(S.size());
	dp[0] = true;
	for (int i = 1; i < S.size(); ++i) {
		for (int j = 0; j < N; ++j) {
			if (i >= A[j].size() && dp[i - A[j].size()]
					&& S.substr(i - A[j].size() + 1, A[j].size()) == A[j]) {
				dp[i] = true;
				break;
			}
		}
	}
	cout << dp.back() << "\n";
	return 0;
}
