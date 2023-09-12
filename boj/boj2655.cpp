#include <bits/stdc++.h>

using namespace std;

using rec = tuple<int, int, int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<rec> A(N);
	for (int i = 0; i < N; ++i) {
		auto &[a, b, c, d] = A[i];
		cin >> b >> c >> a;
		d = i + 1;
	}
	sort(A.rbegin(), A.rend());
	vector<int> dp(N);
	vector<int> par(N, -1);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			if (get<0>(A[i]) < get<0>(A[j]) && get<1>(A[i]) < get<1>(A[j]) && dp[i] < dp[j]) {
				dp[i] = dp[j];
				par[i] = j;
			}
		}
		dp[i] += get<2>(A[i]);
	}
	int p = max_element(dp.begin(), dp.end()) - dp.begin();
	vector<int> B;
	B.push_back(get<3>(A[p]));
	while (par[p] != -1) {
		p = par[p];
		B.push_back(get<3>(A[p]));
	}
	cout << B.size() << "\n";
	for (int i = 0; i < B.size(); ++i) {
		cout << B[i] << "\n";
	}
	return 0;
}
