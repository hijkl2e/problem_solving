#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<vector<int>> G;
vector<int> sz, in, out;

void dfs(int u, int p) {
	sz[u] = 1;
	for (auto &v : G[u]) {
		if (v == p) {
			continue;
		}
		in[v] = out[v] = out[u] + 1;
		dfs(v, u);
		sz[u] += sz[v];
		out[u] = out[v];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	G.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		int x{};
		cin >> x;
		G[x].push_back(i);
	}
	sz.resize(N + 1);
	in.resize(N + 1);
	out.resize(N + 1);
	dfs(0, -1);
	int Q{};
	cin >> Q;
	while (Q--) {
		int M{};
		cin >> M;
		vector<int> A(M);
		for (int i = 0; i < M; ++i) {
			cin >> A[i];
		}
		int ans{};
		for (int i = 0; i < M; ++i) {
			bool yes = true;
			for (int j = 0; j < M; ++j) {
				if (i == j) {
					continue;
				}
				if (in[A[j]] <= in[A[i]] && in[A[i]] <= out[A[j]]) {
					yes = false;
					break;
				}
			}
			if (yes) {
				ans += sz[A[i]];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
