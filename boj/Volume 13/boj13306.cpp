#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

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
	vector<int> par(N + 1);
	for (int i = 2; i <= N; ++i) {
		cin >> par[i];
	}
	vector<iii> A(Q + N - 1);
	deque<bool> B(N + 1, true);
	for (auto &[t, a, b] : A) {
		cin >> t;
		if (t) {
			cin >> a >> b;
		} else {
			cin >> a;
			b = -1;
			B[a] = true;
		}
	}
	UF uf(N + 1);
	deque<bool> C(Q);
	for (int i = A.size() - 1, j = Q - 1; i >= 0; --i) {
		auto &[t, a, b] = A[i];
		if (t) {
			C[j--] = uf.same(a, b);
		} else {
			uf.unite(a, par[a]);
		}
	}
	for (int i = 0; i < Q; ++i) {
		cout << (C[i] ? "YES" : "NO") << "\n";
	}
	return 0;
}
