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
	int select(T k) {
		int p = 1;
		while (2 * p < ft.size()) {
			p *= 2;
		}
		int i = 0;
		while (p) {
			if (i + p < ft.size() && k > ft[i + p]) {
				k -= ft[i + p];
				i += p;
			}
			p /= 2;
		}
		return i + 1;
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

template <typename T = ll>
class RURQ {
public:
	RURQ(int n) : rupq(n), purq(n + 1) { }
	void range_update(int ui, int uj, T v) {
		rupq.range_update(ui, uj, v);
		purq.update(ui, v * (ui - 1));
		purq.update(uj + 1, -v * uj);
	}
	T rsq(int i, int j) {
		return rsq(j) - rsq(i - 1);
	}
	T rsq(int j) {
		return rupq.point_query(j) * j - purq.rsq(j);
	}
private:
	RUPQ<T> rupq;
	FT<T> purq;
};

template <typename T = ll>
class FT2D {
public:
	FT2D(int n, int m) : ft(n + 1, vector<T>(m + 1)) { }
	T rsq(int x1, int y1, int x2, int y2) {
		return rsq(x2, y2) - rsq(x1 - 1, y2) - rsq(x2, y1 - 1) + rsq(x1 - 1, y1 - 1);
	}
	T rsq(int x, int y) {
		T res{};
		while (x) {
			int z = y;
			while (z) {
				res += ft[x][z];
				z -= LSOne(z);
			}
			x -= LSOne(x);
		}
		return res;
	}
	void update(int x, int y, T v) {
		while (x < ft.size()) {
			int z = y;
			while (z < ft[x].size()) {
				ft[x][z] += v;
				z += LSOne(z);
			}
			x += LSOne(x);
		}
	}
private:
	T LSOne(T x) {
		return x & -x;
	}
	vector<vector<T>> ft;
};
