#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
deque<bool> C;
vector<int> d;

void dfs(int x, int p) {
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		d[y] = d[x] + 1;
		dfs(y, x);
	}
	if (!C[x]) {
		d[x] = -1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	G.resize(N + 1);
	C.resize(N + 1);
	d.resize(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 1; i <= N; ++i) {
		int x{};
		cin >> x;
		C[i] = x;
	}
	d[0] = -1;
	dfs(1, -1);
	sort(d.begin(), d.end());
	for (int i = 1; i <= N; ++i) {
		if (d[i] == -1) {
			continue;
		}
		if (d[i - 1] >= d[i]) {
			d[i] = d[i - 1] + 1;
		}
	}
	cout << d[N] + 1 << "\n";
	return 0;
}
