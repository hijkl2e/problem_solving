#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct point {
	ll x{}, y{};
};

struct line {
	point p1{}, p2{};
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

bool are_intersect(const line &l1, const line &l2) {
	int r1 = ccw(l1.p1, l1.p2, l2.p1);
	int r2 = ccw(l1.p1, l1.p2, l2.p2);
	int r3 = ccw(l2.p1, l2.p2, l1.p1);
	int r4 = ccw(l2.p1, l2.p2, l1.p2);
	return r1 * r2 < 1 && r3 * r4 < 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, C{}, K{};
	cin >> R >> C >> K;
	vector<point> A(K);
	for (int i = 0; i < K; ++i) {
		cin >> A[i].x >> A[i].y;
	}
	line ul{{1, 1}, {R + C - 1, C - R + 1}};
	line dl{{1, -1}, {R + C - 1, C - R - 1}};
	vector<point> U{ul.p1, ul.p2};
	vector<point> D{dl.p1, dl.p2};
	for (auto &p : A) {
		line l{{p.x + p.y - 1, p.y - p.x + 1}, {p.x + p.y - 1, p.y - p.x - 1}};
		if (are_intersect(ul, l)) {
			U.push_back(l.p2);
		}
		if (are_intersect(dl, l)) {
			D.push_back(l.p1);
		}
	}
	sort(U.begin(), U.end());
	sort(D.begin(), D.end());
	U = convex_hull(U);
	D = convex_hull(D);
	reverse(D.begin() + 1, D.end());
	bool yes = true;
	for (int k = 0; k < 2; ++k) {
		for (int i = 1, j = 1; i < U.size() - 1; ++i) {
			while (D[j].x < U[i].x) {
				++j;
			}
			if (are_intersect({U[i - 1], U[i]}, {D[j - 1], D[j]})) {
				yes = false;
			}
		}
		swap(U, D);
	}
	cout << yes << "\n";
	return 0;
}
