#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct point {
	ll x{}, y{};
};

bool operator==(point &p1, point &p2) {
	return p1.x == p2.x && p1.y == p2.y;
}

bool operator<=(point &p1, point &p2) {
	return p1.x < p2.x || (p1.x == p2.x && p1.y <= p2.y);
}

ll _ccw(point &p1, point &p2, point &p3) {
	ll ret = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	ret -= p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
	return ret;
}

int ccw(point &p1, point &p2, point &p3) {
	ll res = _ccw(p1, p2, p3);
	return res > 0 ? 1 : res < 0 ? -1 : 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<point> A(4);
	for (int i = 0; i < 4; ++i) {
		cin >> A[i].x >> A[i].y;
	}
	vector<int> B(4);
	for (int i = 0; i < 4; ++i) {
		B[i] = ccw(A[i & 2], A[(i & 2) | 1], A[i ^ 2]);
	}
	bool yes = B[0] * B[1] < 1 && B[2] * B[3] < 1;
	if (count(B.begin(), B.end(), 0) == 4) {
		for (int i = 0; i < 4; i += 2) {
			if (A[i + 1] <= A[i]) {
				swap(A[i], A[i + 1]);
			}
		}
		yes = A[0] <= A[3] && A[2] <= A[1];
	}
	cout << yes << "\n";
	if (!yes) {
		return 0;
	}
	if (count(B.begin(), B.end(), 0) == 4) {
		point *p = A[0] == A[3] ? &A[0] : A[2] == A[1] ? &A[2] : nullptr;
		if (p) {
			cout << p->x << " " << p->y << "\n";
		}
		return 0;
	}
	ll a = abs(_ccw(A[0], A[1], A[2]));
	ll b = abs(_ccw(A[0], A[1], A[3]));
	double c = a * 1.0 / (a + b);
	double x = A[2].x + c * (A[3].x - A[2].x);
	double y = A[2].y + c * (A[3].y - A[2].y);
	cout << fixed << setprecision(15);
	cout << x << " " << y << "\n";
	return 0;
}
