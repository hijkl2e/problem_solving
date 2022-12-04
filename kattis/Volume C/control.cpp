#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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
	UF uf(5e5 + 1);
	int ans{};
	while (N--) {
		int M{};
		cin >> M;
		vector<int> A;
		for (int i = 0; i < M; ++i) {
			int x{};
			cin >> x;
			A.push_back(uf.root(x));
		}
		sort(A.begin(), A.end());
		A.resize(unique(A.begin(), A.end()) - A.begin());
		ll sum{};
		for (int x : A) {
			sum += uf.size(x);
		}
		if (sum == M) {
			for (int x : A) {
				uf.unite(x, A[0]);
			}
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
