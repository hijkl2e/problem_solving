#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int X{}, T{}, M{}, V{}, N{};
	cin >> X >> T >> M >> V >> N;
	vector<int> x(N);
	vector<int> m(N);
	vector<int> c(N);
	for (int i = 0; i < N; ++i) {
		cin >> x[i] >> m[i] >> c[i];
	}
	if (X > V * T) {
		cout << "-1\n";
		return 0;
	}
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		A[i] = x[i] * m[i];
	}
	vector<int> dp(T * V * M - X * M + 1);
	for (int i = 0; i < N; ++i) {
		for (int j = dp.size() - 1; j >= A[i]; --j) {
			dp[j] = max(dp[j], dp[j - A[i]] + c[i]);
		}
	}
	cout << *max_element(dp.begin(), dp.end()) << "\n";
	return 0;
}
