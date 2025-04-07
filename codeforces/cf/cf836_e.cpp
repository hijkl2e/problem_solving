#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

const ll MOD = 1e9 + 7;

vector<vector<ii>> G;
vector<int> B;
ll ans, H;

void dfs(int u) {
	for (auto &[v, w] : G[u]) {
		int x = (B[u] + w) % H;
		if (B[v] == -1) {
			B[v] = x;
			dfs(v);
		} else if (B[v] != x) {
			ans = -1;
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> N >> M >> H;
		ans = 1;
		vector<vector<int>> A(N, vector<int>(M));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				cin >> A[i][j];
			}
		}
		G.assign(M, {});
		for (int i = 0; i < N; ++i) {
			int k = -1;
			for (int j = 0; j < M; ++j) {
				if (A[i][j] == -1) {
					continue;
				} else if (k == -1) {
					k = j;
					continue;
				}
				G[k].push_back({j, (A[i][j] - A[i][k] + H) % H});
				G[j].push_back({k, (A[i][k] - A[i][j] + H) % H});
				k = j;
			}
			if (k == -1) {
				ans = ans * H % MOD;
			}
		}
		B.assign(M, -1);
		int cnt{};
		for (int i = 0; i < M; ++i) {
			if (B[i] == -1) {
				B[i] = 0;
				dfs(i);
				++cnt;
			}
		}
		if (ans == -1) {
			cout << "0\n";
			continue;
		}
		while (--cnt) {
			ans = ans * H % MOD;
		}
		cout << ans << "\n";
	}
	return 0;
}
