#include <bits/stdc++.h>

using namespace std;

struct point {
	int x{}, y{};
};

bool operator<(point &p1, point &p2) {
	return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

int ccw(point &p1, point &p2, point &p3) {
	int res = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	res -= p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
	return res > 0 ? 1 : res < 0 ? -1 : 0;
}

double dist(point &p1, point &p2) {
	return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<point> A(3);
	for (int i = 0; i < 3; ++i) {
		cin >> A[i].x >> A[i].y;
	}
	if (ccw(A[0], A[1], A[2]) == 0) {
		cout << "-1\n";
		return 0;
	}
	vector<double> B(3);
	for (int i = 0; i < 3; ++i) {
		B[i] = dist(A[i], A[(i + 1) % 3]);
	}
	sort(B.begin(), B.end());
	double ans = 2 * (B[2] - B[0]);
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
