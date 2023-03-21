#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 1e9 + 7;

struct point {
	point() { }
	point(ll _x, ll _y) : x(_x), y(_y) { }
	ll x{}, y{};
};

bool operator==(point &p1, point &p2) {
	return p1.x == p2.x && p1.y == p2.y;
}

bool operator!=(point &p1, point &p2) {
	return !(p1 == p2);
}

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
	int N{}, K{};
	cin >> N >> K;
	vector<point> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].x >> A[i].y;
	}
	sort(A.begin(), A.end());
	vector<point> B = convex_hull(A);
	int ans = B.size() == K ? N - K : 0;
	if (B.size() == 2) {
		cout << ans << "\n";
		return 0;
	}
	K -= B.size() - 3;
	for (int i = 0; i < B.size(); ++i) {
		ll a = (i + B.size() - 1) % B.size();
		ll b = (i + 1) % B.size();
		ll minx = min({B[a].x, B[i].x, B[b].x});
		ll maxx = max({B[a].x, B[i].x, B[b].x});
		int lo = lower_bound(A.begin(), A.end(), point(minx, -INF)) - A.begin();
		int hi = upper_bound(A.begin(), A.end(), point(maxx, INF)) - A.begin();
		vector<point> C;
		for (int j = lo; j < hi; ++j) {
			if (A[j] != B[i] && ccw(B[a], B[b], A[j]) < 1) {
				C.push_back(A[j]);
			}
		}
		if (convex_hull(C).size() == K) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
