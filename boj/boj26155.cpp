#include <bits/stdc++.h>

using namespace std;

using di = pair<double, int>;
using edge = tuple<double, int, int>;

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
	vector<edge> E(M);
	for (auto &[p, a, b] : E) {
		cin >> a >> b >> p;
		p = -p;
	}
	sort(E.begin(), E.end());
	int Q{};
	cin >> Q;
	vector<di> A(Q);
	for (int i = 0; i < Q; ++i) {
		cin >> A[i].first;
		A[i].first = -A[i].first;
		A[i].second = i;
	}
	sort(A.begin(), A.end());
	UF uf(N + 1);
	int cnt = N;
	vector<int> ans(Q);
	for (int i = 0, j = 0; i < Q; ++i) {
		auto &[p1, idx] = A[i];
		while (j < E.size()) {
			auto &[p2, a, b] = E[j];
			if (p1 < p2) {
				break;
			}
			if (uf.unite(a, b)) {
				--cnt;
			}
			++j;
		}
		ans[idx] = cnt;
	}
	for (int i = 0; i < Q; ++i) {
		cout << ans[i] << "\n";
	}
	return 0;
}
