#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct point {
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

bool solve(vector<point> &A, point &p) {
	int n = A.size();
	if (ccw(A[0], A[1], p) == -1 || ccw(A[0], A[n - 1], p) == 1) {
		return false;
	}
	int lo = 1, hi = n - 1;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (ccw(A[0], A[mid], p) > -1) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	return ccw(A[lo], A[hi], p) > -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<point> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].x >> A[i].y;
	}
	sort(A.begin(), A.end());
	vector<vector<point>> B;
	deque<bool> C(N);
	while (A.size()) {
		B.push_back(convex_hull(A));
		fill(C.begin(), C.begin() + A.size(), true);
		for (auto &p : B.back()) {
			int x = lower_bound(A.begin(), A.end(), p) - A.begin();
			C[x] = false;
		}
		vector<point> D;
		for (int i = 0; i < A.size(); ++i) {
			if (C[i]) {
				D.push_back(A[i]);
			}
		}
		swap(A, D);
	}
	int Q{};
	cin >> Q;
	while (Q--) {
		point p;
		cin >> p.x >> p.y;
		int lo = -1, hi = B.size();
		while (lo + 1 < hi) {
			int mid = (lo + hi) / 2;
			if (solve(B[mid], p)) {
				lo = mid;
			} else {
				hi = mid;
			}
		}
		cout << hi << "\n";
	}
	return 0;
}
