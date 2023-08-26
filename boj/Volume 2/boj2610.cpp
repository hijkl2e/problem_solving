#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

class UF {
public:
	UF(int N) : par(N), sz(N, 1) {
		for (int i = 0; i < N; ++i) {
			par[i] = i;
		}
	}
	int root(int x) {
		return par[x] == x ? x : (par[x] = root(par[x]));
	}
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	bool unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) {
			return false;
		}
		if (sz[x] < sz[y]) {
			swap(x, y);
		}
		par[y] = x;
		sz[x] += sz[y];
		return true;
	}
	int size(int x) {
		return sz[root(x)];
	}
private:
	vector<int> par, sz;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> G(N + 1);
	UF uf(N + 1);
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		uf.unite(u, v);
	}
	vector<ii> A(N + 1, {-1, 1e9});
	for (int i = 1; i <= N; ++i) {
		vector<int> D(N + 1, -1);
		queue<int> q;
		D[i] = 0;
		q.push(i);
		while (q.size()) {
			int x = q.front(); q.pop();
			for (int y : G[x]) {
				if (D[y] == -1) {
					D[y] = D[x] + 1;
					q.push(y);
				}
			}
		}
		int maxv = *max_element(D.begin(), D.end());
		int r = uf.root(i);
		if (A[r].second > maxv) {
			A[r] = {i, maxv};
		}
	}
	vector<int> B;
	for (int i = 1; i <= N; ++i) {
		if (A[i].first != -1) {
			B.push_back(A[i].first);
		}
	}
	sort(B.begin(), B.end());
	cout << B.size() << "\n";
	for (int x : B) {
		cout << x << "\n";
	}
	return 0;
}
