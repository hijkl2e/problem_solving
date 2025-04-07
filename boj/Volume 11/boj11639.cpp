#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, T{};
	cin >> N >> T;
	vector<int> p(N);
	vector<int> t(N);
	vector<int> d(N);
	for (int i = 0; i < N; ++i) {
		cin >> p[i] >> t[i] >> d[i];
		d[i] = d[i] == -1 ? INF : d[i];
	}
	vector<vector<int>> D(N + 2, vector<int>(N + 2));
	for (int i = 0; i < N + 2; ++i) {
		for (int j = 0; j < N + 2; ++j) {
			cin >> D[i][j];
		}
	}
	vector<vector<int>> dp(N, vector<int>(1 << N, INF));
	for (int i = 0; i < N; ++i) {
		dp[i][1 << i] = D[N][i] + t[i];
	}
	for (int j = 0; j < (1 << N); ++j) {
		for (int i = 0; i < N; ++i) {
			if (dp[i][j] > d[i]) {
				continue;
			}
			for (int k = 0; k < N; ++k) {
				if ((j & (1 << k)) == 0) {
					int &val = dp[k][j | (1 << k)];
					val = min(val, dp[i][j] + D[i][k] + t[k]);
				}
			}
		}
	}
	vector<int> A(1 << N, INF);
	for (int i = 0; i < A.size(); ++i) {
		for (int j = 0; j < N; ++j) {
			if (dp[j][i] <= d[j]) {
				A[i] = min(A[i], dp[j][i] + D[j][N + 1]);
			}
		}
	}
	vector<int> B(1 << N);
	for (int i = 0; i < B.size(); ++i) {
		for (int j = 0; j < N; ++j) {
			if (i & (1 << j)) {
				B[i] += p[j];
			}
		}
	}
	vector<int> C{0};
	int maxv{};
	for (int i = 1; i < A.size(); ++i) {
		if (A[i] > T) {
			continue;
		}
		if (maxv < B[i]) {
			maxv = B[i];
			C.clear();
		}
		if (maxv == B[i]) {
			C.push_back(i);
		}
	}
	for (int i = 0; i < N; ++i) {
		vector<int> v1, v2;
		for (int x : C) {
			if (x & (1 << i)) {
				v1.push_back(x);
			} else {
				v2.push_back(x);
			}
		}
		C = v1.size() ? v1 : v2;
	}
	cout << maxv << "\n";
	for (int i = 0, j = 0; i < N; ++i) {
		if (C[0] & (1 << i)) {
			cout << (j++ ? " " : "") << i + 1;
		}
	}
	cout << "\n";
	return 0;
}
