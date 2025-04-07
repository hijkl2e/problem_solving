#include <bits/stdc++.h>

using namespace std;

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

vector<vector<int>> G;
vector<int> dfs_num, dfs_low;
deque<bool> C;
int dfs_cnt;

void dfs(int x, int p) {
	dfs_num[x] = dfs_low[x] = dfs_cnt++;
	int child{};
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		if (dfs_num[y] == -1) {
			dfs(y, x);
			if (dfs_low[y] >= dfs_num[x] && p != -1) {
				C[x] = false;
			}
			dfs_low[x] = min(dfs_low[x], dfs_low[y]);
			++child;
		} else {
			dfs_low[x] = min(dfs_low[x], dfs_num[y]);
		}
	}
	if (p == -1 && child > 1) {
		C[x] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		cin.ignore();
		G.assign(N, vector<int>());
		for (int i = 0; i < N; ++i) {
			string s;
			getline(cin, s);
			for (int j = 0; j < N; ++j) {
				if (s[j] == '1') {
					G[i].push_back(j);
				}
			}
		}
		UF uf(N);
		for (int u = 0; u < N; ++u) {
			for (int v : G[u]) {
				uf.unite(u, v);
			}
		}
		vector<int> A;
		for (int i = 0; i < N; ++i) {
			if (uf.root(i) == i) {
				A.push_back(i);
			}
		}
		if (A.size() == 1) {
			cout << "0\n";
			continue;
		}
		dfs_num.assign(N, -1);
		dfs_low.resize(N);
		C.assign(N, true);
		dfs_cnt = 0;
		for (int x : A) {
			dfs(x, -1);
		}
		int ans{};
		for (int i = 0; i < N; ++i) {
			if (uf.size(i) == 1 || (G[i].size() + 1 < uf.size(i) && C[i])) {
				ans = i + 1;
				break;
			}
		}
		if (ans) {
			cout << "1\n";
			cout << ans << "\n";
			continue;
		}
		vector<int> B;
		if (A.size() == 2) {
			if (uf.size(A[0]) < uf.size(A[1])) {
				swap(A[0], A[1]);
			}
			B.push_back(A[1]);
			for (int x : G[A[1]]) {
				B.push_back(x);
			}
		} else {
			B.push_back(A[0]);
			B.push_back(A[1]);
		}
		cout << B.size() << "\n";
		for (int i = 0; i < B.size(); ++i) {
			cout << B[i] + 1 << (i == B.size() - 1 ? "\n" : " ");
		}
	}
	return 0;
}
