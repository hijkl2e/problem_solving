#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

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

struct point {
	point() { }
	point(ll _x, ll _y) : x(_x), y(_y) { }
	ll x{}, y{};
};

bool operator<(point &p1, point &p2) {
	return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

int ccw(point &p1, point &p2, point &p3) {
	ll res = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	res -= p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
	return res > 0 ? 1 : res < 0 ? -1 : 0;
}

ll dist(point &p1, point &p2) {
	return (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y);
}

bool compare(point &o, point &p1, point &p2) {
	if ((p1 < o) ^ (p2 < o)) {
		return p2 < p1;
	} else {
		return ccw(o, p1, p2) == 1;
	}
}

point rotate_left(point &o, point &p) {
	return point(o.x + o.y - p.y, o.y - o.x + p.x);
}

point rotate_right(point &o, point &p) {
	return point(o.x - o.y + p.y, o.y + o.x - p.x);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<point> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].x >> A[i].y;
		A[i].y *= -1;
	}
	vector<point> B;
	vector<int> L, R;
	vector<ii> D;
	FT ft(N - 1);
	ll ans{};
	for (int i = 0; i < N; ++i) {
		B.clear();
		for (int j = 0; j < N; ++j) {
			if (A[i].x < A[j].x || A[i].y < A[j].y) {
				B.push_back(A[j]);
			}
		}
		int sz = B.size();
		sort(B.begin(), B.end(), [&](point &p1, point &p2) {
			return compare(A[i], p1, p2);
		});
		L.resize(sz);
		for (int j = 0; j < sz; ++j) {
			L[j] = max(j == 0 ? j : L[j - 1], j);
			point r = rotate_left(A[i], B[j]);
			while (L[j] + 1 < sz && ccw(A[i], r, B[L[j] + 1]) == -1) {
				++L[j];
			}
		}
		R.resize(sz);
		for (int j = sz - 1; j >= 0; --j) {
			R[j] = min(j == sz - 1 ? j : R[j + 1], j);
			point r = rotate_right(A[i], B[j]);
			while (R[j] > 0 && ccw(A[i], r, B[R[j] - 1]) == 1) {
				--R[j];
			}
		}
		D.resize(sz);
		for (int j = 0; j < sz; ++j) {
			D[j] = {dist(B[j], A[i]), j};
		}
		sort(D.begin(), D.end());
		for (int j = 0, k = 1; j < sz; j = k++) {
			while (k < sz && D[j].first == D[k].first) {
				++k;
			}
			for (int l = j; l < k; ++l) {
				int p = D[l].second;
				if (A[i].x < B[p].x && A[i].y < B[p].y) {
					ans += ft.rsq(p + 1, L[p] + 1) * ft.rsq(R[p] + 1, p + 1);
				}
			}
			for (int l = j; l < k; ++l) {
				ft.update(D[l].second + 1, 1);
			}
		}
		for (int j = 0; j < sz; ++j) {
			ft.update(j + 1, -1);
		}
	}
	cout << ans << "\n";
	return 0;
}
