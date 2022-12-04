#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <typename T = ll>
class FT {
public:
	FT(int n) : ft(n + 1) { }
	T rsq(int i, int j) {
		return rsq(j) - rsq(i - 1);
	}
	T rsq(int j) {
		T res{};
		while (j) {
			res += ft[j];
			j -= LSOne(j);
		}
		return res;
	}
	void update(int i, T v) {
		while (i < ft.size()) {
			ft[i] += v;
			i += LSOne(i);
		}
	}
private:
	T LSOne(T x) {
		return x & -x;
	}
	vector<T> ft;
};

vector<vector<int>> G;
vector<int> A, B, D;

void dfs(int x, int p) {
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		A[y] = B[y] = B[x] + 1;
		D[y] = D[x] + 1;
		dfs(y, x);
		B[x] = B[y];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, C{};
	cin >> N >> C;
	G.resize(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int x{}, y{};
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	A.resize(N + 1);
	B.resize(N + 1);
	D.resize(N + 1);
	A[C] = B[C] = D[C] = 1;
	dfs(C, -1);
	FT ft(N);
	int Q{};
	cin >> Q;
	while (Q--) {
		int q{}, x{};
		cin >> q >> x;
		if (q == 1) {
			ft.update(A[x], 1);
		} else {
			cout << ft.rsq(A[x], B[x]) * D[x] << "\n";
		}
	}
	return 0;
}
