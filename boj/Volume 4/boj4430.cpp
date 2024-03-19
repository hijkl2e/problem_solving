#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A, B;
	int w{}, s{};
	while (cin >> w >> s) {
		A.push_back(w);
		B.push_back(s);
	}
	int n = A.size();
	vector<int> C(n);
	for (int i = 0; i < n; ++i) {
		C[i] = i;
	}
	sort(C.begin(), C.end(), [&](int a, int b) {
		return A[a] > A[b] || (A[a] == A[b] && B[a] < B[b]);
	});
	vector<int> dp(n, 1);
	vector<int> par(n, -1);
	for (int x : C) {
		for (int i = 0; i < n; ++i) {
			if (A[i] < A[x] && B[i] > B[x] && dp[i] < dp[x] + 1) {
				dp[i] = dp[x] + 1;
				par[i] = x;
			}
		}
	}
	int p = max_element(dp.begin(), dp.end()) - dp.begin();
	cout << dp[p] << "\n";
	while (par[p] != -1) {
		cout << p + 1 << "\n";
		p = par[p];
	}
	cout << p + 1 << "\n";
	return 0;
}
