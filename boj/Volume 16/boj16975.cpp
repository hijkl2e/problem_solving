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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	RUPQ ft(N);
	for (int i = 1; i <= N; ++i) {
		int x{};
		cin >> x;
		ft.range_update(i, i, x);
	}
	int M{};
	cin >> M;
	while (M--) {
		int q{};
		cin >> q;
		if (q == 1) {
			int a{}, b{}, c{};
			cin >> a >> b >> c;
			ft.range_update(a, b, c);
		} else {
			int x{};
			cin >> x;
			cout << ft.point_query(x) << "\n";
		}
	}
	return 0;
}
