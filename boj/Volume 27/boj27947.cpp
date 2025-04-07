#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct point {
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
	ll N{}, M{};
	cin >> N >> M;
	N += 3, M *= 2;
	vector<point> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].x >> A[i].y;
	}
	int lo = 3, hi = N + 1;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		vector<point> B(A.begin(), A.begin() + mid);
		sort(B.begin(), B.end());
		B = convex_hull(B);
		ll res{};
		for (int i = 0; i < B.size(); ++i) {
			int j = (i + 1) % B.size();
			res += B[i].x * B[j].y - B[i].y * B[j].x;
		}
		res = abs(res);
		if (res < M) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	string ans = hi == N + 1 ? "draw" : hi % 2 ? "wider" : "wapas";
	cout << ans << "\n";
	return 0;
}
