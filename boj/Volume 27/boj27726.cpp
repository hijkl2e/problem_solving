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
	int N{};
	cin >> N;
	vector<int> M(3);
	for (int i = 0; i < 3; ++i) {
		cin >> M[i];
	}
	vector<UF> A(3, UF(N + 1));
	for (int i = 0; i < 3; ++i) {
		while (M[i]--) {
			int u{}, v{};
			cin >> u >> v;
			A[i].unite(u, v);
		}
	}
	map<iii, vector<int>> B;
	for (int i = 1; i <= N; ++i) {
		B[{A[0].root(i), A[1].root(i), A[2].root(i)}].push_back(i);
	}
	vector<vector<int>> C;
	for (auto &p : B) {
		if (p.second.size() > 1) {
			C.push_back(p.second);
		}
	}
	sort(C.begin(), C.end(), [](vector<int> &v1, vector<int> &v2) {
		return v1[0] < v2[0];
	});
	cout << C.size() << "\n";
	for (auto &v : C) {
		for (int i = 0; i < v.size(); ++i) {
			cout << v[i] << (i == v.size() - 1 ? "\n" : " ");
		}
	}
	return 0;
}
