#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G, A;

void dfs(int x, int p, int d) {
	A[d].push_back(x);
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		dfs(y, x, d + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		G.assign(N + 1, {});
		for (int i = 0; i < N - 1; ++i) {
			int u{}, v{};
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		bool flag{};
		for (int i = 1; i <= N; ++i) {
			if (G[i].size() == N - 1) {
				flag = true;
				break;
			}
		}
		if (flag) {
			cout << "-1\n";
			continue;
		}
		A.assign(N + 1, {});
		for (int i = 1; i <= N; ++i) {
			if (G[i].size() == 1) {
				dfs(i, -1, 0);
				break;
			}
		}
		vector<int> B;
		for (int i = 1; i < N; i += 2) {
			copy(A[i].begin(), A[i].end(), back_inserter(B));
		}
		for (int i = 0; i < N; i += 2) {
			copy(A[i].begin(), A[i].end(), back_inserter(B));
		}
		for (int i = 0; i < N; ++i) {
			cout << B[i] << (i == N - 1 ? "\n" : " ");
		}
	}
	return 0;
}
