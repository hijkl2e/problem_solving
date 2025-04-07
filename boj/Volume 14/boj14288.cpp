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
vector<int> in, out;
int cntr;

void dfs(int x) {
	in[x] = out[x] = ++cntr;
	for (int y : G[x]) {
		dfs(y);
		out[x] = out[y];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	G.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		int p{};
		cin >> p;
		if (i > 1) {
			G[p].push_back(i);
		}
	}
	in.resize(N + 1);
	out.resize(N + 1);
	dfs(1);
	RUPQ ft1(N);
	FT ft2(N);
	bool rev{};
	while (M--) {
		int q{}, a{}, b{};
		cin >> q;
		if (q == 1) {
			cin >> a >> b;
			if (rev) {
				ft2.update(in[a], b);
			} else {
				ft1.range_update(in[a], out[a], b);
			}
		} else if (q == 2) {
			cin >> a;
			cout << ft1.point_query(in[a]) + ft2.rsq(in[a], out[a]) << "\n";
		} else {
			rev ^= true;
		}
	}
	return 0;
}
