#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, T{};
	cin >> N >> T;
	vector<ll> M(N);
	vector<ll> P(N);
	vector<ll> R(N);
	for (int i = 0; i < N; ++i) {
		cin >> M[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> P[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> R[i];
	}
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		A[i] = i;
	}
	sort(A.begin(), A.end(), [&](int i, int j) {
		return R[i] * P[j] < R[j] * P[i];
	});
	vector<ll> dp(T + 1, -INF);
	dp[0] = 0;
	for (int k : A) {
		for (int i = T; i >= R[k]; --i) {
			dp[i] = max(dp[i], dp[i - R[k]] + M[k] - i * P[k]);
		}
	}
	ll ans = *max_element(dp.begin(), dp.end());
	cout << ans << "\n";
	return 0;
}
