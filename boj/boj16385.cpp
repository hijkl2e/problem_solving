#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;

int N;
vector<ii> A;
vector<int> D;
vector<vector<int>> dp;

int dist(ii &a, ii &b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int solve(int u, int x) {
	if (dp[u][x] != INF) {
		return dp[u][x];
	} else if (x == 0) {
		return dp[u][x] = dist(A[u], A[N]);
	}
	int &val = dp[u][x];
	for (int i = 0; i < N; ++i) {
		if (x & (1 << D[i])) {
			val = min(val, dist(A[u], A[i]) + solve(i, x & ~(1 << D[i])));
		}
	}
	return val;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	A.resize(N + 1);
	vector<string> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first >> A[i].second >> B[i];
	}
	vector<string> C(B.begin(), B.end());
	sort(C.begin(), C.end());
	C.resize(unique(C.begin(), C.end()) - C.begin());
	D.resize(N);
	for (int i = 0; i < N; ++i) {
		D[i] = lower_bound(C.begin(), C.end(), B[i]) - C.begin();
	}
	dp.assign(N + 1, vector<int>(1 << C.size(), INF));
	cout << solve(N, (1 << C.size()) - 1) << "\n";
	return 0;
}
