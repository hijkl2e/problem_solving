#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
int d;

int dfs(int x, int p) {
	if (x == d) {
		return 0;
	}
	int ret{};
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		ret += dfs(y, x);
	}
	ret = max(ret, 1);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	G.resize(N);
	int r{};
	for (int i = 0; i < N; ++i) {
		int x{};
		cin >> x;
		if (x == -1) {
			r = i;
		} else {
			G[x].push_back(i);
		}
	}
	cin >> d;
	int ans = dfs(r, -1);
	cout << ans << "\n";
	return 0;
}
