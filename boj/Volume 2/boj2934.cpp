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
	RUPQ ft(100001);
	while (N--) {
		int l{}, r{};
		cin >> l >> r;
		int x = ft.point_query(l);
		int y = ft.point_query(r);
		cout << x + y << "\n";
		ft.range_update(l, l, -x);
		ft.range_update(r, r, -y);
		ft.range_update(l + 1, r - 1, 1);
	}
	return 0;
}
