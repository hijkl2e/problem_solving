#include <bits/stdc++.h>
#include "wiring.h"

using namespace std;

using ll = long long;
using ii = pair<int, int>;

const ll INF = 4e18;

long long min_total_length(std::vector<int> r, std::vector<int> b) {
	int N = r.size();
	int M = b.size();
	vector<int> &A = r;
	vector<int> &B = b;
	vector<ii> C(N + M + 1);
	for (int i = 0, j = 0, k = 1; k < C.size(); ++k) {
		if (j == M || (i < N && A[i] <= B[j])) {
			C[k] = {A[i++], 0};
		} else {
			C[k] = {B[j++], 1};
		}
	}
	vector<ll> dp(N + M + 1);
	vector<queue<int>> q(2);
	vector<int> last(2, -1);
	for (int i = 1; i < C.size(); ++i) {
		auto &[x, y] = C[i];
		int z = y ^ 1;
		dp[i] = last[z] == -1 ? INF : (x - C[last[z]].first);
		while (q[z].size()) {
			int u = q[z].front(); q[z].pop();
			dp[u] = min<ll>(dp[u], x - C[u].first);
		}
		q[y].push(i);
		last[y] = i;
	}
	vector<ll> D(N + M + 1);
	vector<int> E(N + M + 1, -1);
	int cnt = M;
	E[cnt] = 0;
	for (int i = 1; i < C.size(); ++i) {
		auto &[x, y] = C[i];
		D[i] = D[i - 1] + (y ? -1 : 1) * x;
		cnt += y ? -1 : 1;
		dp[i] += dp[i - 1];
		int &z = E[cnt];
		if (z != -1) {
			dp[i] = min(dp[i], dp[z] + abs(D[i] - D[z]));
		}
		z = i;
	}
	return dp.back();
}
