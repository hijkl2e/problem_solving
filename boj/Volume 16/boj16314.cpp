#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<int> L;

void dfs(int x, int p) {
	if (G[x].size() == 1) {
		L.push_back(x);
	}
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		dfs(y, x);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, H{};
	cin >> N >> H;
	G.resize(N);
	for (int i = 0; i < N - 1; ++i) {
		int a{}, b{};
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(H, -1);
	int sz = (L.size() + 1) / 2;
	cout << sz << "\n";
	for (int i = 0; i < L.size() / 2; ++i) {
		cout << L[i] << " " << L[i + sz] << "\n";
	}
	if (L.size() % 2) {
		cout << L[L.size() / 2] << " " << L[0] << "\n";
	}
	return 0;
}
