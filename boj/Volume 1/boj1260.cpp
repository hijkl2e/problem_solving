#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
deque<bool> vst;
vector<int> A, B;

void dfs(int x) {
	vst[x] = true;
	A.push_back(x);
	for (int y : G[x]) {
		if (vst[y]) {
			continue;
		}
		dfs(y);
	}
}

void bfs(int s) {
	fill(vst.begin(), vst.end(), false);
	queue<int> q;
	vst[s] = true;
	q.push(s);
	while (q.size()) {
		int x = q.front(); q.pop();
		B.push_back(x);
		for (int y : G[x]) {
			if (vst[y]) {
				continue;
			}
			vst[y] = true;
			q.push(y);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, V{};
	cin >> N >> M >> V;
	G.resize(N + 1);
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 1; i <= N; ++i) {
		sort(G[i].begin(), G[i].end());
	}
	vst.resize(N + 1);
	dfs(V);
	bfs(V);
	for (int i = 0; i < A.size(); ++i) {
		cout << A[i] << (i == A.size() - 1 ? "\n" : " ");
	}
	for (int i = 0; i < B.size(); ++i) {
		cout << B[i] << (i == B.size() - 1 ? "\n" : " ");
	}
	return 0;
}
