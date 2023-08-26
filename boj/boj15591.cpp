#include <bits/stdc++.h>

using namespace std;

using edge = tuple<int, int, int>;
using query = tuple<int, int, int>;

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
	int N{}, Q{};
	cin >> N >> Q;
	vector<edge> E(N - 1);
	for (auto &[w, a, b] : E) {
		cin >> a >> b >> w;
	}
	sort(E.rbegin(), E.rend());
	vector<query> A(Q);
	for (int i = 0; i < Q; ++i) {
		auto &[k, v, idx] = A[i];
		cin >> k >> v;
		idx = i;
	}
	sort(A.rbegin(), A.rend());
	vector<int> B(Q);
	UF uf(N + 1);
	for (int i = 0, j = 0; i < Q; ++i) {
		auto &[k, v, idx] = A[i];
		while (j < N - 1) {
			auto &[w, a, b] = E[j];
			if (k > w) {
				break;
			}
			uf.unite(a, b);
			++j;
		}
		B[idx] = uf.size(v) - 1;
	}
	for (int i = 0; i < Q; ++i) {
		cout << B[i] << "\n";
	}
	return 0;
}
