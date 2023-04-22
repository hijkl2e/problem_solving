#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

vector<vector<ii>> G;
vector<vector<int>> d, par;
vector<int> B;

void dfs(int u, int p) {
	B.push_back(u);
	par[u][0] = p;
	for (auto &[v, w] : G[u]) {
		if (v == p) {
			continue;
		}
		d[v][0] = w;
		dfs(v, u);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	G.resize(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	d.assign(N + 1, vector<int>(17));
	par.assign(N + 1, vector<int>(17));
	dfs(1, 1);
	for (int x : B) {
		for (int i = 1; i < 17; ++i) {
			d[x][i] = d[x][i - 1] + d[par[x][i - 1]][i - 1];
			par[x][i] = par[par[x][i - 1]][i - 1];
		}
	}
	vector<int> C(N + 1);
	for (int i = 1; i <= N; ++i) {
		int k = i;
		for (int j = 16; j >= 0; --j) {
			if (A[i] >= d[k][j]) {
				A[i] -= d[k][j];
				k = par[k][j];
			}
		}
		C[i] = k;
	}
	for (int i = 1; i <= N; ++i) {
		cout << C[i] << "\n";
	}
	return 0;
}
