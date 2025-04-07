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

template <typename T = ll>
class RURQ {
public:
	RURQ(int n) : rupq(n), purq(n + 1) { }
	RURQ(vector<T> &A) : rupq(A.size()), purq(A) { }
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<ll> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
		A[i] = -A[i];
	}
	RURQ ft(A);
	M += K;
	while (M--) {
		ll a{}, b{}, c{}, d{};
		cin >> a >> b >> c;
		if (a == 1) {
			cin >> d;
			ft.range_update(b, c, d);
		} else {
			cout << ft.rsq(b, c) << "\n";
		}
	}
	return 0;
}
