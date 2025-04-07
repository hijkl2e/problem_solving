#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int solve(vector<ii> &A, int K) {
	int ret{};
	for (int i = 0, j = 0; i < A.size(); ++i) {
		if (j < A[i].second) {
			int q = (A[i].second - j - 1) / K + 1;
			ret += 2 * q * A[i].first;
			j += q * K;
		}
		j -= A[i].second;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<ii> A, B;
	while (N--) {
		int x{}, t{};
		cin >> x >> t;
		if (x > 0) {
			A.push_back({x, t});
		} else {
			B.push_back({-x, t});
		}
	}
	sort(A.rbegin(), A.rend());
	sort(B.rbegin(), B.rend());
	int ans = solve(A, K) + solve(B, K);
	cout << ans << "\n";
	return 0;
}
