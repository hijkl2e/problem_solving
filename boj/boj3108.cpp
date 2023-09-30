#include <bits/stdc++.h>

using namespace std;

using rec = tuple<int, int, int, int>;

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
	vector<rec> A(N);
	for (auto &[x1, y1, x2, y2] : A) {
		cin >> x1 >> y1 >> x2 >> y2;
	}
	A.push_back({});
	sort(A.begin(), A.end());
	UF uf(N + 1);
	int ans = N;
	for (int i = 0; i <= N; ++i) {
		auto &[x1, y1, x2, y2] = A[i];
		for (int j = i + 1; j <= N; ++j) {
			auto &[x3, y3, x4, y4] = A[j];
			if (x1 <= x4 && x3 <= x2 && y1 <= y4 && y3 <= y2
					&& !(x1 < x3 && x4 < x2 && y1 < y3 && y4 < y2)
					&& uf.unite(i, j)) {
				--ans;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
