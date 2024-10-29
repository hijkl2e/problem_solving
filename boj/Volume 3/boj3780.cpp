#include <bits/stdc++.h>

using namespace std;

class UF {
public:
	UF(int N) : par(N), D(N) {
		for (int i = 0; i < N; ++i) {
			par[i] = i;
		}
	}
	int root(int x) {
		if (par[x] == x) {
			return x;
		}
		int y = par[x];
		par[x] = root(par[x]);
		D[x] += D[y];
		return par[x];
	}
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	bool unite(int x, int y) {
		par[y] = x;
		D[y] = abs(y - x) % 1000;
		return true;
	}
	int dist(int x) {
		root(x);
		return D[x];
	}
private:
	vector<int> par, D;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		UF uf(N + 1);
		char q{};
		while (cin >> q, q != 'O') {
			int x{};
			cin >> x;
			if (q == 'E') {
				cout << uf.dist(x) << "\n";
			} else {
				int y{};
				cin >> y;
				uf.unite(y, x);
			}
		}
	}
	return 0;
}
