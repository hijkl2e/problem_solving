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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<int> x(M);
	vector<int> y(M);
	for (int i = 0; i < M; ++i) {
		cin >> x[i] >> y[i];
	}
	vector<int> A(K);
	for (int i = 0; i < K; ++i) {
		UF uf(N + 1);
		int sum{}, cnt{};
		for (int j = i; j < M; ++j) {
			if (uf.unite(x[j], y[j])) {
				sum += j + 1;
				++cnt;
			}
		}
		if (cnt == N - 1) {
			A[i] = sum;
		} else {
			break;
		}
	}
	for (int i = 0; i < K; ++i) {
		cout << A[i] << (i == K - 1 ? "\n" : " ");
	}
	return 0;
}
