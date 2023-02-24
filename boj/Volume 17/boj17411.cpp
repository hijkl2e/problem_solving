#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> dp{-MOD};
	vector<vector<int>> B{{-MOD}};
	vector<vector<int>> C{{1}};
	for (int i = 0; i < N; ++i) {
		int j = lower_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
		int k = lower_bound(B[j - 1].rbegin(), B[j - 1].rend(), A[i]) - B[j - 1].rbegin();
		int x = (C[j - 1].back() - (k == B[j - 1].size() ? 0 : *(C[j - 1].rbegin() + k)) + MOD) % MOD;
		if (j == dp.size()) {
			dp.push_back(A[i]);
			B.push_back({A[i]});
			C.push_back({x});
		} else if (dp[j] == A[i]) {
			C[j].back() = (C[j].back() + x) % MOD;
		} else {
			dp[j] = A[i];
			B[j].push_back(A[i]);
			C[j].push_back((C[j].back() + x) % MOD);
		}
	}
	cout << dp.size() - 1 << " " << C.back().back() << "\n";
	return 0;
}
