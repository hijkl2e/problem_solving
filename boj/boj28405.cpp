#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, P{};
	cin >> N >> P;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<int> B(N + 1);
	multiset<ll> S;
	for (int i = 1, j = 1; i <= N; ++i) {
		S.insert(A[i]);
		while (*--S.end() + i - j > P) {
			S.erase(S.find(A[j++]));
		}
		B[i] = j;
	}
	S.clear();
	deque<int> dq;
	vector<ll> dp(N + 1);
	for (int i = 1; i <= N; ++i) {
		while (dq.size() && dq.front() < B[i]) {
			int x = dq.front();
			dq.pop_front();
			if (dq.size()) {
				S.erase(S.find(dp[x] + A[dq.front()] - x));
			}
		}
		while (dq.size() && A[dq.back()] <= A[i]) {
			int x = dq.back();
			dq.pop_back();
			if (dq.size()) {
				S.erase(S.find(dp[dq.back()] + A[x] - dq.back()));
			}
		}
		if (dq.size()) {
			S.insert(dp[dq.back()] + A[i] - dq.back());
		}
		dq.push_back(i);
		dp[i] = dp[B[i] - 1] + A[dq.front()] + i - B[i];
		if (S.size()) {
			dp[i] = min(dp[i], *S.begin() + i - 1);
		}
	}
	cout << dp[N] << "\n";
	return 0;
}
