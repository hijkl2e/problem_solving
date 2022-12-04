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

vector<int> sieve() {
	vector<int> p(1000001);
	for (int i = 0; i < p.size(); ++i) {
		p[i] = i;
	}
	for (int i = 2; i < p.size(); ++i) {
		if (p[i] == i) {
			for (int j = 2 * i; j < p.size(); j += i) {
				p[j] = i;
			}
		}
	}
	return p;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> P = sieve();
	UF uf(1000001);
	for (int i = 0; i < N; ++i) {
		int x = A[i];
		int y = P[x];
		while (x > 1) {
			int z = P[x];
			while (x % z == 0) {
				x /= z;
			}
			uf.unite(y, z);
		}
	}
	vector<int> B(1000001);
	for (int i = 0; i < N; ++i) {
		++B[uf.root(P[A[i]])];
	}
	int ans = *max_element(B.begin(), B.end());
	cout << ans << "\n";
	return 0;
}
