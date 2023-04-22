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
	if (A.size() < 3) {
		return true;
	}
	for (int i = 0; i < A.size(); ++i) {
		int j = (i + 1) % A.size();
		if (ccw(A[i], A[j], p) == -1) {
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	point p;
	cin >> N >> p.x >> p.y;
	vector<point> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].x >> A[i].y;
	}
	sort(A.begin(), A.end());
	deque<bool> C(N);
	int ans{};
	while (A.size()) {
		vector<point> B = convex_hull(A);
		if (solve(B, p)) {
			break;
		}
		fill(C.begin(), C.begin() + A.size(), true);
		for (int i = 0; i < B.size(); ++i) {
			int x = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
			C[x] = false;
		}
		vector<point> D;
		for (int i = 0; i < A.size(); ++i) {
			if (C[i]) {
				D.push_back(A[i]);
			}
		}
		swap(A, D);
		++ans;
	}
	cout << ans << "\n";
	return 0;
}
