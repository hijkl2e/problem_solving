#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

struct point {
	point() { }
	point(ll _x, ll _y) : x(_x), y(_y) { }
	ll x{}, y{};
};

bool operator<(point &p1, point &p2) {
	return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

int ccw(const point &p1, const point &p2, const point &p3) {
	ll res = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	res -= p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
	return res > 0 ? 1 : res < 0 ? -1 : 0;
}

vector<point> convex_hull(vector<point> &A) {
	int n = A.size(), k{};
	vector<point> H(2 * n);
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && ccw(H[k - 2], H[k - 1], A[i]) < 1) {
			--k;
		}
		H[k++] = A[i];
	}
	for (int i = n - 2, t = k + 1; i >= 0; --i) {
		while (k >= t && ccw(H[k - 2], H[k - 1], A[i]) < 1) {
			--k;
		}
		H[k++] = A[i];
	}
	H.resize(k - 1);
	return H;
}

int N;
vector<int> x, y, dx, dy;

ll f(int t) {
	vector<point> A(N);
	for (int i = 0; i < N; ++i) {
		A[i] = {x[i] + t * dx[i], y[i] + t * dy[i]};
	}
	sort(A.begin(), A.end());
	A = convex_hull(A);
	ll d{};
	for (int i = 0, j = 1; i < A.size(); ++i) {
		int ni = (i + 1) % A.size();
		while (true) {
			int nj = (j + 1) % A.size();
			if (ccw(point(0, 0), point(A[ni].x - A[i].x, A[ni].y - A[i].y),
					point(A[nj].x - A[j].x, A[nj].y - A[j].y)) == 1) {
				j = nj;
			} else {
				break;
			}
		}
		ll nd = (A[i].x - A[j].x) * (A[i].x - A[j].x) + (A[i].y - A[j].y) * (A[i].y - A[j].y);
		d = max(d, nd);
	}
	return d;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> N >> T;
	x.resize(N);
	y.resize(N);
	dx.resize(N);
	dy.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> x[i] >> y[i] >> dx[i] >> dy[i];
	}
	int lo = 0, hi = T;
	while (hi - lo > 2) {
		int d = (hi - lo) / 3;
		int m1 = lo + d;
		int m2 = hi - d;
		if (f(m1) > f(m2)) {
			lo = m1;
		} else {
			hi = m2;
		}
	}
	ll ans = INF, p{};
	for (int i = lo; i <= hi; ++i) {
		ll res = f(i);
		if (ans > res) {
			ans = res;
			p = i;
		}
	}
	cout << p << "\n" << ans << "\n";
	return 0;
}
