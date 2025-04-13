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

bool solve(vector<point> &A, point &p) {
	int n = A.size();
	if (ccw(A[0], A[1], p) < 1 || ccw(A[0], A[n - 1], p) > -1) {
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
	return ccw(A[lo], A[hi], p) == 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<point> A(N);
	vector<point> B(M);
	vector<point> C(K);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].x >> A[i].y;
	}
	for (int i = 0; i < M; ++i) {
		cin >> B[i].x >> B[i].y;
	}
	for (int i = 0; i < K; ++i) {
		cin >> C[i].x >> C[i].y;
	}
	int ans{};
	for (int i = 0; i < K; ++i) {
		if (!solve(A, C[i]) || solve(B, C[i])) {
			++ans;
		}
	}
	if (ans) {
		cout << ans << "\n";
	} else {
		cout << "YES\n";
	}
	return 0;
}
