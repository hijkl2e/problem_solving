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

template <typename T = ll>
class RUPQ {
public:
	RUPQ(int n) : ft(n + 1) { }
	void range_update(int ui, int uj, T v) {
		ft.update(ui, v);
		ft.update(uj + 1, -v);
	}
	T point_query(int i) {
		return ft.rsq(i);
	}
private:
	FT<T> ft;
};

vector<vector<int>> G;
vector<int> A, B;

void dfs(int x) {
	for (int y : G[x]) {
		A[y] = B[y] = B[x] + 1;
		dfs(y);
		B[x] = B[y];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	G.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		int x{};
		cin >> x;
		if (i > 1) {
			G[x].push_back(i);
		}
	}
	A.resize(N + 1);
	B.resize(N + 1);
	A[1] = B[1] = 1;
	dfs(1);
	RUPQ ft(N);
	while (M--) {
		int q{}, a{}, b{};
		cin >> q >> a;
		if (q == 1) {
			cin >> b;
			ft.range_update(A[a], B[a], b);
		} else {
			cout << ft.point_query(A[a]) << "\n";
		}
	}
	return 0;
}
