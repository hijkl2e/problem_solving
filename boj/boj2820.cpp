#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <typename T = ll>
class FT {
public:
	FT(int n) : ft(n + 1) { }
	FT(vector<T> &A) : ft(A.size()) {
		for (int i = 1; i < ft.size(); ++i) {
			ft[i] += A[i];
			if (i + LSOne(i) < ft.size()) {
				ft[i + LSOne(i)] += ft[i];
			}
		}
	}
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
vector<int> in, out;
int cntr;

void dfs(int x) {
	in[x] = ++cntr;
	for (int y : G[x]) {
		dfs(y);
	}
	out[x] = cntr;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	G.resize(N + 1);
	vector<int> A(N + 1);
	cin >> A[1];
	for (int i = 2; i <= N; ++i) {
		int p{};
		cin >> A[i] >> p;
		G[p].push_back(i);
	}
	in.resize(N + 1);
	out.resize(N + 1);
	dfs(1);
	RUPQ ft(N);
	for (int i = 1; i <= N; ++i) {
		ft.range_update(in[i], in[i], A[i]);
	}
	while (M--) {
		char c{};
		int a{}, x{};
		cin >> c >> a;
		if (c == 'p') {
			cin >> x;
			ft.range_update(in[a] + 1, out[a], x);
		} else {
			cout << ft.point_query(in[a]) << "\n";
		}
	}
	return 0;
}
