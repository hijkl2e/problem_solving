#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

struct point {
	int x{}, y{};
};

bool operator<(point &p1, point &p2) {
	return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

int _ccw(point &p1, point &p2, point &p3) {
	int res = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	res -= p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
	return res;
}

int ccw(point &p1, point &p2, point &p3) {
	int res = _ccw(p1, p2, p3);
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

double dist(point &p1, point &p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	for (int tc = 1; cin >> N, N; ++tc) {
		vector<point> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i].x >> A[i].y;
		}
		sort(A.begin(), A.end());
		vector<point> B = convex_hull(A);
		B.push_back(B[0]);
		double minv = 1e9;
		for (int i = 1; i < B.size(); ++i) {
			int maxv{};
			for (int j = 0; j < N; ++j) {
				maxv = max(maxv, _ccw(B[i - 1], B[i], A[j]));
			}
			minv = min(minv, maxv / dist(B[i - 1], B[i]));
		}
		int ans = 1000 * minv - EPS;
		ans = ans / 10 + 1;
		cout << "Case " << tc << ": " << ans / 100 << ".";
		cout << setw(2) << setfill('0') << ans % 100 << "\n";
	}
	return 0;
}
