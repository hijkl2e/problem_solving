#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct point {
	point() { }
	point(ll _x, ll _y) : x(_x), y(_y) { }
	ll x{}, y{};
};

bool operator<(const point &p1, const point &p2) {
	return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

int ccw(point &p1, point &p2, point &p3) {
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<point> A(N);
	vector<point> B(M);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].x >> A[i].y;
	}
	for (int i = 0; i < M; ++i) {
		cin >> B[i].x >> B[i].y;
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	vector<point> C(N * M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			C[i * M + j] = point(A[i].x + B[j].x, A[i].y + B[j].y);
		}
	}
	sort(C.begin(), C.end());
	C = convex_hull(C);
	cout << C.size() << "\n";
	for (auto &p : C) {
		cout << p.x << " " << p.y << "\n";
	}
	return 0;
}
