#include <bits/stdc++.h>

using namespace std;

using edge = tuple<int, int, int>;

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
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	vector<edge> E;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[i][j] == '0') {
				continue;
			}
			int w = islower(A[i][j]) ? (A[i][j] - 'a' + 1) : (A[i][j] - 'A' + 27);
			E.push_back({w, i, j});
		}
	}
	sort(E.begin(), E.end());
	UF uf(N);
	int cnt{}, ans{};
	for (auto &[w, u, v] : E) {
		if (uf.unite(u, v)) {
			++cnt;
		} else {
			ans += w;
		}
	}
	cout << (cnt == N - 1 ? ans : -1) << "\n";
	return 0;
}
