#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<int> d;

void dfs(int x) {
	for (int y : G[x]) {
		d[y] = d[x] ^ 1;
		dfs(y);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	G.resize(N + 1);
	for (int i = 2; i <= N; ++i) {
		int p{};
		cin >> p;
		G[p].push_back(i);
	}
	d.resize(N + 1);
	dfs(1);
	int cnt = count(d.begin(), d.end(), 1);
	int ans = max(cnt, N - cnt);
	cout << ans << "\n";
	return 0;
}
