#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, L{};
	cin >> N >> L;
	cin.ignore();
	string S;
	getline(cin, S);
	vector<int> A(N + 1);
	A[0] = N + 1;
	for (int i = 1; i <= N; ++i) {
		A[i] = A[i - 1] + (S[i - 1] == 'K' ? 1 : -1);
	}
	vector<deque<int>> B(2 * N + 3);
	vector<int> dp(N + 1, INF);
	B[N + 1].push_back(0);
	dp[0] = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = -1; j < 2; ++j) {
			auto &dq = B[A[i] + j];
			while (dq.size() && i - dq.front() > L) {
				dq.pop_front();
			}
			if (dq.size()) {
				dp[i] = min(dp[i], dp[dq.front()] + 1);
			}
		}
		auto &dq = B[A[i]];
		while (dq.size() && dp[dq.back()] >= dp[i]) {
			dq.pop_back();
		}
		dq.push_back(i);
	}
	cout << dp[N] << "\n";
	return 0;
}
