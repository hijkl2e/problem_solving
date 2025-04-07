#include <bits/stdc++.h>

using namespace std;

struct point {
	int x{}, y{}, n{};
};

bool operator==(const point &p1, const point &p2) {
	return p1.n == p2.n;
}

bool operator<(point &p1, point &p2) {
	return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

int ccw(point &p1, point &p2, point &p3) {
	int res = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	res -= p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
	return res > 0 ? 1 : res < 0 ? -1 : 0;
}

vector<point> convex_hull(vector<point> &A) {
	int n = A.size(), k{};
	vector<point> H(2 * n);
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && ccw(H[k - 2], H[k - 1], A[i]) == -1) {
			--k;
		}
		H[k++] = A[i];
	}
	for (int i = n - 2, t = k + 1; i >= 0; --i) {
		while (k >= t && ccw(H[k - 2], H[k - 1], A[i]) == -1) {
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
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<point> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i].x >> A[i].y;
			A[i].n = i;
		}
		sort(A.begin(), A.end());
		vector<point> B = convex_hull(A);
		B.resize(find(B.begin(), B.end(), A[N - 1]) - B.begin() + 1);
		deque<bool> C(N, true);
		for (int i = 0; i < B.size(); ++i) {
			C[B[i].n] = false;
		}
		vector<int> D;
		for (int i = 0; i < N; ++i) {
			if (C[A[i].n]) {
				D.push_back(A[i].n);
			}
		}
		for (int i = B.size() - 1; i >= 0; --i) {
			D.push_back(B[i].n);
		}
		for (int i = 0; i < N; ++i) {
			cout << D[i] << (i == N - 1 ? "\n" : " ");
		}
	}
	return 0;
}
