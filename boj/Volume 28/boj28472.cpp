#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

vector<vector<int>> G;
vector<int> A;

void dfs(int x, int p, bool f) {
	if (A[x] != -1) {
		return;
	} else if (f) {
		A[x] = INF;
	}
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		dfs(y, x, f ^ true);
		if (f) {
			A[x] = min(A[x], A[y]);
		} else {
			A[x] = max(A[x], A[y]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, R{};
	cin >> N >> R;
	G.resize(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	A.resize(N + 1, -1);
	int L{};
	cin >> L;
	while (L--) {
		int k{}, t{};
		cin >> k >> t;
		A[k] = t;
	}
	dfs(R, -1, false);
	int Q{};
	cin >> Q;
	while (Q--) {
		int x{};
		cin >> x;
		cout << A[x] << "\n";
	}
	return 0;
}
