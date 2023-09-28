#include <bits/stdc++.h>

using namespace std;

int get_mex(vector<int> &A, int s) {
	static deque<bool> B;
	int maxv = *max_element(A.begin() + s, A.end());
	B.assign(maxv + 2, false);
	for (int i = s; i < A.size(); ++i) {
		B[A[i]] = true;
	}
	int mex{};
	while (B[mex]) {
		++mex;
	}
	return mex;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> A(N + 1);
		for (int i = 1; i <= N; ++i) {
			cin >> A[i];
		}
		vector<int> B(N + 2);
		vector<bitset<8192>> dp(N + 1);
		dp[0][0] = true;
		for (int i = 1; i <= N; ++i) {
			fill(B.begin(), B.end(), 0);
			int mex{}, max_mex = get_mex(A, i);
			if (A[i] > max_mex) {
				dp[i] |= dp[i - 1];
				continue;
			}
			for (int j = i; j <= N && mex < max_mex; ++j) {
				++B[A[j]];
				if (B[A[i]] > 1) {
					break;
				}
				int n_mex = mex;
				while (B[n_mex]) {
					++n_mex;
				}
				if (mex == n_mex || n_mex < A[i]) {
					mex = n_mex;
					continue;
				}
				for (int k = 0; k < 8192; ++k) {
					if (dp[i - 1][k]) {
						dp[j][k ^ n_mex] = true;
					}
				}
				mex = n_mex;
			}
			dp[i] |= dp[i - 1];
		}
		int ans = 8191;
		while (!dp[N][ans]) {
			--ans;
		}
		cout << ans << "\n";
	}
	return 0;
}
