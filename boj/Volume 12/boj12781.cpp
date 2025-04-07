#include <bits/stdc++.h>

using namespace std;

struct point {
	int x{}, y{};
};

int ccw(point &p1, point &p2, point &p3) {
	int res = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	res -= p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
	return res > 0 ? 1 : res < 0 ? -1 : 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<point> A(4);
	for (int i = 0; i < 4; ++i) {
		cin >> A[i].x >> A[i].y;
	}
	bool yes = true;
	for (int i = 0; i < 4; i += 2) {
		yes &= ccw(A[i], A[i | 1], A[i ^ 2]) * ccw(A[i], A[i | 1], A[i ^ 3]) == -1;
	}
	cout << yes << "\n";
	return 0;
}
