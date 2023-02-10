#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<int> A, ind, c, sz, dp, c_sz, t_sz, t_dp;

void dfs(int x, bool f) {
	sz[x] = 1;
	dp[x] = f;
	for (int y : G[x]) {
		c[y] = c[x];
		dfs(y, !f);
		sz[x] += sz[y];
		dp[x] += dp[y];
	}
	if (ind[x]) {
		++c_sz[c[x]];
		t_sz[c[x]] += sz[x];
		t_dp[c[x]] += dp[x];
		if (sz[A[x]] == 0) {
			c[A[x]] = c[x];
			dfs(A[x], !f);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	A.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	ind.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		++ind[A[i]];
	}
	queue<int> q;
	for (int i = 1; i <= N; ++i) {
		if (ind[i] == 0) {
			q.push(i);
		}
	}
	while (q.size()) {
		int x = q.front(); q.pop();
		if (--ind[A[x]] == 0) {
			q.push(A[x]);
		}
	}
	G.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		if (ind[i] == 0) {
			G[A[i]].push_back(i);
		}
	}
	c.resize(N + 1);
	sz.resize(N + 1);
	dp.resize(N + 1);
	c_sz.resize(N + 1);
	t_sz.resize(N + 1);
	t_dp.resize(N + 1);
	int cn{};
	for (int i = 1; i <= N; ++i) {
		if (ind[i] && sz[i] == 0) {
			c[i] = cn++;
			dfs(i, true);
		}
	}
	int odd = cn;
	for (int i = 0; i < cn; ++i) {
		if (c_sz[i] % 2) {
			odd = odd == cn ? i : -1;
		}
	}
	if (odd == -1) {
		cout << "-1\n";
		return 0;
	}
	int cnt{};
	for (int i = 0; i < cn; ++i) {
		if (c_sz[i] % 2 == 0) {
			cnt += max(t_dp[i], t_sz[i] - t_dp[i]);
		}
	}
	vector<int> ans;
	if (odd == cn) {
		for (int i = 1; i <= N; ++i) {
			if (ind[i]) {
				continue;
			}
			int j = c[i];
			int x = t_dp[j] + sz[i] - 2 * dp[i];
			if (cnt - max(t_dp[j], t_sz[j] - t_dp[j]) + max(x, t_sz[j] - x) >= M) {
				ans.push_back(i);
			}
		}
	} else {
		int x{}, y{};
		for (int i = 1; i <= N; ++i) {
			if (ind[i] && c[i] == odd) {
				x = y = i;
				break;
			}
		}
		int z = t_dp[odd];
		for (int i = 0; i == 0 || x != y; ++i) {
			z += sz[x] - 2 * dp[x];
			if (cnt + max(z, t_sz[odd] - z) >= M) {
				ans.push_back(x);
			}
			x = A[x];
		}
		sort(ans.begin(), ans.end());
	}
	if (ans.empty()) {
		cout << "-1\n";
	} else {
		cout << ans.size() << "\n";
		for (int i = 0; i < ans.size(); ++i) {
			cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
		}
	}
	return 0;
}
