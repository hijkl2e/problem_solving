#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct point {
	ll x{}, y{};
};

bool operator<(point &p1, point &p2) {
	return p1.y < p2.y || (p1.y == p2.y && p1.x < p2.x);
}

int ccw(point &p1, point &p2, point &p3) {
	ll res = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	res -= p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
	return res > 0 ? 1 : res < 0 ? -1 : 0;
}

bool solve(vector<point> &A, point &p) {
	bool ret{};
	for (int i = 0; i < A.size(); ++i) {
		int j = i, k = (i + 1) % A.size();
		if (A[k] < A[j]) {
			swap(j, k);
		}
		if (p.y < A[j].y || A[k].y < p.y) {
			continue;
		}
		int res = ccw(A[j], A[k], p);
		if (res == 1 && p.y < A[k].y) {
			ret ^= true;
		} else if (res == 0 && (A[j].y < A[k].y || (A[j].x <= p.x && p.x <= A[k].x))) {
			ret = true;
			break;
		}
	}
	return ret;
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
	for (int i = 0; i < 3; ++i) {
		point p;
		cin >> p.x >> p.y;
		cout << solve(A, p) << "\n";
	}
	return 0;
}
