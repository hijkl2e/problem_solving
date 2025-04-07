#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<int> d;

void dfs(int x) {
	for (int y : G[x]) {
		d[y] = d[x] + 1;
		dfs(y);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	G.resize(N);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
	}
	d.resize(N);
	dfs(0);
	int ans{};
	for (int i = 0; i < N; ++i) {
		int x{};
		cin >> x;
		if (x == K) {
			ans = d[i];
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
