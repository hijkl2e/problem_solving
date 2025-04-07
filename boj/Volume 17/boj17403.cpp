#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct point {
	ll x{}, y{};
};

using pi = pair<point, int>;

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
	int N{};
	cin >> N;
	vector<pi> A(N);
	for (int i = 0; i < N; ++i) {
		point &p = A[i].first;
		cin >> p.x >> p.y;
		A[i].second = i;
	}
	sort(A.begin(), A.end());
	vector<point> B(N);
	for (int i = 0; i < N; ++i) {
		B[i] = A[i].first;
	}
	vector<int> C(N);
	for (int i = 1; B.size(); ++i) {
		sort(B.begin(), B.end());
		vector<point> D = convex_hull(B);
		if (D.size() < 3) {
			break;
		}
		for (auto &p : D) {
			auto it = lower_bound(A.begin(), A.end(), make_pair(p, -1));
			C[it->second] = i;
		}
		B.clear();
		for (auto &[p, x] : A) {
			if (C[x] == 0) {
				B.push_back(p);
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		cout << C[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
