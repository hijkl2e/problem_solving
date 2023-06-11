#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

vector<vector<int>> G;
vector<int> vst;
vector<iii> A;

int dfs(int x, int p) {
	vst[x] = 1;
	vector<int> B;
	for (int y : G[x]) {
		if (y == p) {
			continue;
		} else if (vst[y] == 1) {
			B.push_back(y);
		} else if (vst[y] == -1) {
			int z = dfs(y, x);
			if (z == -1) {
				B.push_back(y);
			} else {
				A.push_back({x, y, z});
			}
		}
	}
	vst[x] = 0;
	for (int i = 0; i + 1 < B.size(); i += 2) {
		A.push_back({B[i], x, B[i + 1]});
	}
	return B.size() % 2 ? B.back() : -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	G.resize(N + 1);
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	vst.assign(N + 1, -1);
	for (int i = 1; i <= N; ++i) {
		if (vst[i] == -1) {
			dfs(i, -1);
		}
	}
	cout << A.size() << "\n";
	for (auto &[u, v, w] : A) {
		cout << u << " " << v << " " << w << "\n";
	}
	return 0;
}
